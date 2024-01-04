/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalem < absalem@student.42abudhabi.ae    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:14:54 by absalem           #+#    #+#             */
/*   Updated: 2024/01/04 15:09:06 by absalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int parsing(int ac, char **av, t_parameter *parameter) 
{
    if (!ac || !av) 
	{
        ft_putstr_fd(USAGE, 2);
        return 1;
    }
    if (ac != 5 && ac != 6) 
	{
        ft_putstr_fd(USAGE, 2);
        return 1;
    }
    if (check_input(ac, av) == 1)
        return 1;
	parameter->number_of_philo = ft_atoi(av[1]);
	parameter->time_to_die = ft_atoi(av[2]);
	parameter->time_to_eat = ft_atoi(av[3]);
	parameter->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		parameter->num_times_to_eat = ft_atoi(av[5]);
	else 
		parameter->num_times_to_eat = -1;
	// if(max_input_check)
    return 0;
}
