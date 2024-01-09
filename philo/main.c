/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalem < absalem@student.42abudhabi.ae    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:28:18 by absalem           #+#    #+#             */
/*   Updated: 2024/01/09 17:24:38 by absalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



int main(int ac, char **av)
{
	t_program program;

	if(parsing(ac, av) != 0)
		return (0);
	philo_init(&program, av);
	return (0);
}
