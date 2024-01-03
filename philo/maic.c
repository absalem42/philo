/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maic.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalem < absalem@student.42abudhabi.ae    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:28:18 by absalem           #+#    #+#             */
/*   Updated: 2024/01/03 18:33:32 by absalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	philo_init(t_philo **philo_p, char **av)
{
	if (!av)
		return ;
	if (check_num(av))
	{
		ft_putstr_fd("invliad irgument",2);
	}
}

int main(int ac, char **av)
{
	t_program *philo_p;
	
	philo_p = NULL;
	if (ac == 5 || ac == 6)
	{
		parsing()
	}
	else
	{
		ft_putstr_fd("./philo_one number_philosopher time_to_die time_to_eat time_to_sleep [number_of_time_each_philosophers_must_eat]\n",2);
		return (0);
	}
		
}
