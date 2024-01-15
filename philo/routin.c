/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalem < absalem@student.42abudhabi.ae    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:12:18 by absalem           #+#    #+#             */
/*   Updated: 2024/01/15 17:26:59 by absalem          ###   ########.fr       */
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

// int philosophers_are_alive(t_philo *philo)
// {
// 	pthread_mutex_lock(philo->dead_lock);
// 	if (*philo->dead == 1)
// 	{
// 		pthread_mutex_unlock(philo->dead_lock);
// 		return (0);
// 	}
// 	pthread_mutex_unlock(philo->dead_lock);
// 	return (1);
// }


void	print_message(t_philo *philo, char *message)
{
	pthread_mutex_lock(philo->write_lock);
	if (!philosophers_are_alive(philo))
	{
		printf("%llu %d %s\n", get_time() - philo->start_time, philo->id,
			message);
	}
	pthread_mutex_unlock(philo->write_lock);
}

void	eating_philo(t_philo *philo)
{
	
	if (philo->id % 2 == 0)
		pthread_mutex_lock(philo->r_fork);
	else
		pthread_mutex_lock(philo->l_fork);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	pthread_mutex_lock(philo->l_fork);
	print_message(philo, "has taken a fork");
	if (philo->params->num_of_philos == 1)
	{
		ft_usleep(philo->params->time_to_die);
		pthread_mutex_unlock(philo->l_fork);
		return ;
	}
	pthread_mutex_lock(philo->r_fork);
	print_message(philo, "has taken a fork");
	print_message(philo, "is eating");
	philo->eating = 1;
	ft_usleep(philo->params->time_to_eat);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	philo->eating = 0;
	print_message(philo, "is sleeping");
	ft_usleep(philo->params->time_to_sleep);
	print_message(philo, "is thinking");
}

int check_dead(t_philo *philo)
{	
	if (get_time() - philo->last_meal >= philo->params->time_to_die
						&& philo->eating == 0) 
		{
        	pthread_mutex_lock(philo->dead_lock);
        	*philo->dead = 1;
        	pthread_mutex_unlock(philo->dead_lock);
        	return(1);
        	// break;
    	}
	return (0);
}

void	death(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	*philo->dead = 1;
	pthread_mutex_unlock((philo->dead_lock));
}

int	philosophers_are_alive(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
	{
		pthread_mutex_unlock(philo->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}
int check_time_of_death(t_philo *philo) 
{
	int			i;
	size_t	time;

	i = 0;
	while (i < philo->params->num_of_philos)
	{
		pthread_mutex_lock(philo->dead_lock);
		time = philo[i].last_meal;
		pthread_mutex_unlock(philo->dead_lock);
		if (get_time() - time >= philo->params->time_to_die)
		{
			print_message(&philo[i], "died");
			death(philo);
		}
		if (philosophers_are_alive(philo))
			return (1);
		i++;
	}
	return (0);
}

int check_done_eat(t_philo *philo) 
{
	int			i;
	int			j;
	int			ate;

	i = 0;
	j = 0;
	while (i < philo->params->num_of_philos)
	{
		pthread_mutex_lock(philo->meal_lock);
		ate = philo[i].meals_eaten;
		pthread_mutex_unlock(philo->meal_lock);
		if (ate == philo->params->num_times_to_eat)
		{
			j++;
		}
		if (j == philo->params->num_times_to_eat)
			return (1);
		i++;
	}
	return (0);
}


void	obeserv(t_philo *philos)
{
	while (1)
	{
		usleep(200);
		if (check_time_of_death(philos) || check_done_eat(philos))
			break ;
	}
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(philo->params->time_to_eat);
	while (!philosophers_are_alive(philo))
	{
		
		// eating_philo(philo);
		
		if (philo->params->num_times_to_eat != -1 && philo->meals_eaten == philo->params->num_times_to_eat)
			break ;
		print_message(philo, "is sleeping");
		ft_usleep(philo->params->time_to_sleep);
		print_message(philo, "is thinking");
		
	}
	// if (philo->params->num_of_philos == 1)
			// break ;
	return (arg);
}





			
	// while (philosophers_are_alive(philo))
	// {
	// 	eat_sleep_think(philo);
	// 	if (philo->params->num_of_philos == 1)
	// 		break ;
	// }