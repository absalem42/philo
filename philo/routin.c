/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalem < absalem@student.42abudhabi.ae    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:12:18 by absalem           #+#    #+#             */
/*   Updated: 2024/02/01 15:54:31 by absalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating_philo(t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(philo->r_fork);
		pthread_mutex_lock(philo->l_fork);
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		pthread_mutex_lock(philo->r_fork);
	}
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_time();
	philo->meals_eaten++;
	philo->eating = 1;
	pthread_mutex_unlock(philo->meal_lock);
	print_message(philo, "has taken a fork");
	print_message(philo, "has taken a fork");
	print_message(philo, "is eating");
	ft_usleep(philo->params->time_to_eat, philo);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_lock(philo->meal_lock);
	philo->eating = 0;
	pthread_mutex_unlock(philo->meal_lock);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->params->num_of_philos == 1)
		return (NULL);
	if (philo->id % 2 == 0)
		ft_usleep(philo->params->time_to_eat, philo);
	while (!philosophers_are_not_alive(philo))
	{
		eating_philo(philo);
		pthread_mutex_lock(philo->meal_lock);
		if (philo->meals_eaten == philo->params->num_times_to_eat
			&& philo->eating == 0)
		{
			pthread_mutex_unlock(philo->meal_lock);
			break ;
		}
		pthread_mutex_unlock(philo->meal_lock);
		print_message(philo, "is sleeping");
		ft_usleep(philo->params->time_to_sleep, philo);
		print_message(philo, "is thinking");
		if (philo->params->num_of_philos % 2)
			ft_usleep(philo->params->time_to_eat, philo);
	}
	return (arg);
}
