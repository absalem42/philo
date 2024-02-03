/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalem < absalem@student.42abudhabi.ae    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:10:52 by absalem           #+#    #+#             */
/*   Updated: 2024/02/03 11:05:39 by absalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	death(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	*philo->dead = 1;
	pthread_mutex_unlock((philo->dead_lock));
}

int	philosophers_are_not_alive(t_philo *philo)
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

int	check_time_of_death(t_philo *philo)
{
	int		i;
	size_t	time;

	i = 0;
	while (i < philo->params->num_of_philos)
	{
		pthread_mutex_lock(philo[i].meal_lock);
		time = get_time() - philo[i].last_meal;
		if (time > philo[i].params->time_to_die)
		{
			print_message(&philo[i], "died");
			death(philo);
		}
		if (philosophers_are_not_alive(philo))
			return (pthread_mutex_unlock(philo[i].meal_lock), 1);
		pthread_mutex_unlock(philo[i].meal_lock);
		i++;
	}
	return (0);
}

int	check_done_eat(t_philo *philo)
{
	int	i;
	int	j;
	int	ate;

	i = 0;
	j = 0;
	while (i < philo->params->num_of_philos)
	{
		pthread_mutex_lock(philo->meal_lock);
		ate = philo[i].meals_eaten;
		if (ate == philo->params->num_times_to_eat && philo[i].eating == 0)
		{
			pthread_mutex_unlock(philo->meal_lock);
			j++;
		}
		else
			pthread_mutex_unlock(philo->meal_lock);
		if (j == philo->params->num_of_philos)
		{
			death(philo);
			return (1);
		}
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
