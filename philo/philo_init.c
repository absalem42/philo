/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalem < absalem@student.42abudhabi.ae    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:13:38 by absalem           #+#    #+#             */
/*   Updated: 2024/01/10 14:24:37 by absalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_philo(t_program *program, t_params *params)
{
    int i;

    
    i = 0;
    while (i < program->params.num_of_philos) 
    {
        program->philos[i].id = i + 1;
        program->philos[i].params = params;
        program->philos[i].eating = 0;
        program->philos[i].meals_eaten = 0;
        program->philos[i].last_meal = 
        program->philos[i].dead_lock = &program->dead_lock;
        program->philos[i].meal_lock = &program->meal_lock;
        program->philos[i].write_lock = &program->write_lock;
        program->philos[i].l_fork = &program->forks[i];
        program->philos[i].r_fork = &program->forks[(i + 1) % params->num_of_philos];
        
        i++;
    }
}

void    mutex_init(t_program *program, t_params *params)
{
    int i; 
    
    i = 0;
    program->dead_flag = 0;
    pthread_mutex_init(&program->dead_lock, NULL);
    pthread_mutex_init(&program->meal_lock, NULL);
    pthread_mutex_init(&program->write_lock, NULL);
    while (i < params->num_of_philos) 
    {
        pthread_mutex_init(&program->forks[i], NULL);
        i++;
    }
    i = 0;
}

void	philo_init(t_program *program, char **av)
{
	if (!av)
		return ;
    
    mutex_init(&program, &program->params);
    init_philo(&program, &program->params);
}
