/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_handel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalem < absalem@student.42abudhabi.ae    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 14:17:44 by absalem           #+#    #+#             */
/*   Updated: 2024/01/14 19:31:30 by absalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void thread_obeserv(t_program *program)
// {
//     pthread_create(&program->obeserv, NULL, obeserv, program->philos);
// }

// void join_obeserv(t_program *program)
// {
//     pthread_join(program->obeserv, NULL);
// }

void thread_creat(t_philo *philos)
{
    int i;
     
    i = 0;
    philos->start_time = get_time();
    while(i < philos->params->num_of_philos)
    {
        pthread_create(&philos[i].thread, NULL, &routine, &philos[i]);
        i++;
    }
}

void join_thread(t_philo *philos)
{
    int i; 

    i = 0;
    while(i < philos->params->num_of_philos)
    {
        pthread_join(philos[i].thread, NULL);
        i++;
    }
}