/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalem < absalem@student.42abudhabi.ae    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:13:38 by absalem           #+#    #+#             */
/*   Updated: 2024/01/15 14:33:29 by absalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_philo(t_program *program, t_params *params)
{
    t_philo *philos;
    int i;

    philos = program->philos;
    i = 0;
    while (i < params->num_of_philos) 
    {
        philos[i].id = i + 1;
        philos[i].params = params;
        philos[i].eating = 0;
        philos[i].meals_eaten = 0;
        philos[i].last_meal = get_time();
        philos[i].start_time = get_time();
        philos[i].dead = &program->dead_flag;
        philos[i].dead_lock = &program->dead_lock;
        philos[i].meal_lock = &program->meal_lock;
        philos[i].write_lock = &program->write_lock;
        philos[i].l_fork = &program->forks[i];
        philos[i].r_fork = &program->forks[(i + 1) % params->num_of_philos];
        i++;
    }
}

void    mutex_init(t_program *program, t_params *params)
{
    int i; 
    
    i = 0;
    pthread_mutex_init(&program->dead_lock, NULL);
    pthread_mutex_init(&program->meal_lock, NULL);
    pthread_mutex_init(&program->write_lock, NULL);
    while (i < params->num_of_philos) 
    {
        pthread_mutex_init(&program->forks[i], NULL);
        i++;
    }
}

void    init_thread(t_philo *philos, t_program *program)
{
    thread_creat(philos);
    obeserv(philos);
    join_thread(philos);
    destroy_mutexes(program);
    
}

void	philo_init(t_program *program)
{
    
    program->dead_flag = -1;
    mutex_init(program, &program->params);
    init_philo(program, &program->params);
    init_thread(program->philos, program);
    
    
}
