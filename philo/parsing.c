/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalem < absalem@student.42abudhabi.ae    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:14:54 by absalem           #+#    #+#             */
/*   Updated: 2024/01/09 16:11:58 by absalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int parsing(int ac, char **av) 
{
    if (!ac || !av) 
	{
        ft_putstr_fd(USAGE, 2);
        return 0;
    }
    if (ac > 6 || ac < 5)
	{
        ft_putstr_fd(USAGE, 2);
        return 0;
    }
    if (check_input(ac, av) == 1)
    {
        ft_putstr_fd("Invalid arguments\n",2);
        return (0);
        
    }
    if (ft_atoi(av[1]) > 200
		|| ft_atoi(av[2]) < 60 || ft_atoi(av[3]) < 60
		|| ft_atoi(av[4]) < 60 || ft_atoi(av[1]) < 1)
	{
		ft_putstr_fd("Invalid arguments\n",2);
		return (0);
	}
	else if (ft_atoi(av[ac - 1]) <= 0 && ac == 6)
	{
		printf("Invalid arguments\n");
		return (0);
	}
	// parameter->number_of_philo = ft_atoi(av[1]);
	// parameter->time_to_die = ft_atoi(av[2]);
	// parameter->time_to_eat = ft_atoi(av[3]);
	// parameter->time_to_sleep = ft_atoi(av[4]);
	// if (ac == 6)
	// 	parameter->num_times_to_eat = ft_atoi(av[5]);
	// else 
	// 	parameter->num_times_to_eat = -1;
	// if(max_input_check)
    return 1;
}
