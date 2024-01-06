/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalem <absalem@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:28:18 by absalem           #+#    #+#             */
/*   Updated: 2024/01/06 21:49:48 by absalem          ###   ########.fr       */
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
	t_program philo_p;
	
	if(parsing(ac, av, &philo_p.parameter) == 1)
		return (1);
	
	return (0);
}
