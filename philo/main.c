/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalem < absalem@student.42abudhabi.ae    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:28:18 by absalem           #+#    #+#             */
/*   Updated: 2024/01/10 16:11:23 by absalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



int main(int ac, char **av)
{
	t_program program;

	if(parsing(ac, av, &program.params) != 0)
		return (0);
	// printf("dfdf");
	philo_init(&program, av);
	destroy_mutexes(&program);
	return (0);
}
