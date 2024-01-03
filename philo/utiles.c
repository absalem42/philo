/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalem < absalem@student.42abudhabi.ae    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:06:43 by absalem           #+#    #+#             */
/*   Updated: 2024/01/03 18:32:22 by absalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL || fd < 0)
		return ;
	if (*s != '\0')
	{
		write(fd, s, 1);
		ft_putstr_fd(s + 1, fd);
	}
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	check_num(char **av)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while(av[j])
	{
		i = 0;
		while (av[j][i]) 
		{
			if (!ft_isdigit(av[j][i]))
				return 1;
			i++;
		}
		j++;
	}
	return 0;
}
