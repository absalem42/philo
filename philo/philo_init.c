/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalem < absalem@student.42abudhabi.ae    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:13:38 by absalem           #+#    #+#             */
/*   Updated: 2024/01/09 17:30:39 by absalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    mutex_init(t_program **program)
{
    int i = 0;
    
    program->dead_flag = 0;

    pthread_mutex_init(&program->dead_lock, NULL);
    pthread_mutex_init(&program->meal_lock, NULL);
    pthread_mutex_init(&program->write_lock, NULL);

    while (i < MAX_NUM_PHILOSOPHERS; ++i) {
        pthread_mutex_init(&program->forks[i], NULL);
    }

    // Initialize philosophers
    for (int i = 0; i < MAX_NUM_PHILOSOPHERS; ++i) 
    {
        // Set philosopher-specific attributes as needed
        // For example, program->philos[i].id = i;

        // Set mutex pointers for each philosopher
        program->philos[i].dead_lock = &program->dead_lock;
        program->philos[i].meal_lock = &program->meal_lock;
        program->philos[i].write_lock = &program->write_lock;

        // Set fork mutex pointers for each philosopher
        program->philos[i].l_fork = &program->forks[i];
        program->philos[i].r_fork = &program->forks[(i + 1) % MAX_NUM_PHILOSOPHERS];
}

void	philo_init(t_program **program, char **av)
{
	if (!av)
		return ;
    mutex_init(&program);
	program->number_of_philo = ft_atoi(av[1]);
	parameter->time_to_die = ft_atoi(av[2]);
	parameter->time_to_eat = ft_atoi(av[3]);
	parameter->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		parameter->num_times_to_eat = ft_atoi(av[5]);
	else 
		parameter->num_times_to_eat = -1;
}