/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalem < absalem@student.42abudhabi.ae    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:06:43 by absalem           #+#    #+#             */
/*   Updated: 2024/01/04 16:29:09 by absalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL || fd < 0)
		return ;
	int i = 0;
	while(s[i])
	{
		write(fd,&s[i],1);
		i++;
	}
}

int is_valid_number(char *str) 
{
   if (*str && (*str == '+'))
		str++;
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int check_input(int ac, char **av) 
{
    int i ;
	i = 1;
    if (av[0] == NULL)
        return 1;

    while (i < ac)
	{
        if (!is_valid_number(av[i])) 
		{
            ft_putstr_fd(ERROR_IR, 2);
            return 1;
        }
        i++;
    }
    return 0;
}

// int	ft_usleep(size_t milliseconds)
// {
// 	size_t	start;

// 	start = get_current_time();
// 	while ((get_current_time() - start) < milliseconds)
// 		usleep(500);
// 	return (0);
// }
