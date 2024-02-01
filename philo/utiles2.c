/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalem < absalem@student.42abudhabi.ae    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:42:34 by absalem           #+#    #+#             */
/*   Updated: 2024/02/01 19:23:54 by absalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int	i;
	int	value;

	i = 0;
	value = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		return (-1);
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = (value * 10) + (str[i] - 48);
		i++;
	}
	if (value < 0)
		return (-1);
	return (value);
}

void	print_message(t_philo *philo, char *message)
{
	pthread_mutex_lock(philo->write_lock);
	if (!philosophers_are_not_alive(philo))
	{
		printf("%llu %d %s\n", get_time() - philo->start_time, philo->id,
			message);
	}
	pthread_mutex_unlock(philo->write_lock);
}
