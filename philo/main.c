/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalem < absalem@student.42abudhabi.ae    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:28:18 by absalem           #+#    #+#             */
/*   Updated: 2024/02/01 16:19:58 by absalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thread_creat(t_philo *philos)
{
	int	i;

	i = 0;
	philos->start_time = get_time();
	while (i < philos->params->num_of_philos)
	{
		pthread_create(&philos[i].thread, NULL, &routine, &philos[i]);
		i++;
	}
}

void	join_thread(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->params->num_of_philos)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_program	program;

	if (parsing(ac, av, &program.params) != 0)
		return (0);
	philo_init(&program);
	return (0);
}
