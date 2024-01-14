/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalem < absalem@student.42abudhabi.ae    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:12:18 by absalem           #+#    #+#             */
/*   Updated: 2024/01/14 18:55:07 by absalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void    *routin(void *data)
// {
//     t_philo *philo;

//     philo = (t_program *)data;
//     if (philo->id % 2 == 0)
//         ft_usleep(philo->params->time_to_eat);
//     while (!ft_check_died(philo))
// 	{
// 		philo_eat(philo);
// 		eat_sleep_think(philo);
// 		if (philo->params->num_philosophers == 1)
// 			break ;
// 		print(phil, phil->id, "is sleeping");
// 		time_pause(phil, phil->info->time_sleep);
// 		print(phil, phil->id, "is thinking");
// 	}
	
//     return (data);
// }
int philosophers_are_alive(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
	{
		pthread_mutex_unlock(philo->dead_lock);
		return (0);
	}
	pthread_mutex_unlock(philo->dead_lock);
	return (1);
}


void	print_message(t_philo *philo, char *message)
{
	pthread_mutex_lock(philo->write_lock);
	if (philosophers_are_alive(philo))
	{
		printf("%llu %d %s\n", get_time() - philo->start_time, philo->id,
			message);
	}
	pthread_mutex_unlock(philo->write_lock);
}

void	eating_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	pthread_mutex_lock(philo->l_fork);
	print_message(philo, "has taken a fork");
	if (philo->params->num_of_philos == 1)
	{
		ft_usleep(philo->params->time_to_die);
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
		return ;
	}
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_time();
	pthread_mutex_unlock(philo->meal_lock);
	print_message(philo, "is eating");
	ft_usleep(philo->params->time_to_eat);
	pthread_mutex_lock(philo->meal_lock);
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);

	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	// check_time_of_death(philo);
	print_message(philo, "is sleeping");
	ft_usleep(philo->params->time_to_sleep);
	print_message(philo, "is thinking");
}

int check_dead(t_philo *philo)
{	
	if (get_time() - philo->last_meal >= philo->params->time_to_die) 
		{
        	pthread_mutex_lock(philo->dead_lock);
        	*philo->dead = 1;
        	pthread_mutex_unlock(philo->dead_lock);
        	return(1);
        	// break;
    	}
	return (0);
}

int check_time_of_death(t_philo *philo) 
{
	int i;
	
	i = 0;
	while(i < philo->params->num_of_philos)
	{
		if(!check_dead(&philo[i]))
		{
			pthread_mutex_lock(philo[i].dead_lock);
            print_message(&philo[i], "is dead");
			pthread_mutex_unlock(philo[i].dead_lock);
			return (1);
		}
		// pthread_mutex_unlock(philo[i].dead_lock);
		i++;
	}
	return (0);
}

void	*obeserv(void *philos)
{
	t_philo	*philo;
	int i;

	i = 0;
	philo = (t_philo *)philos;
	
	while(1)
	{
		usleep(200);
		if(check_time_of_death(philo))
			break;
	}
	return (philos);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(philo->params->time_to_eat);
	while (1)
	{
		if (check_time_of_death(philo))
			break ;
		eating_philo(philo);
	}
	// if (philo->params->num_of_philos == 1)
			// break ;
	return (NULL);
}





			
	// while (philosophers_are_alive(philo))
	// {
	// 	eat_sleep_think(philo);
	// 	if (philo->params->num_of_philos == 1)
	// 		break ;
	// }