/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalem < absalem@student.42abudhabi.ae    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:42:34 by absalem           #+#    #+#             */
/*   Updated: 2024/01/13 12:54:44 by absalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int	i;
	int	k;
	int	value;

	i = 0;
	k = 1;
	value = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		return (-1);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = (value * 10) + (str[i] - 48);
		i++;
	}
	if (value < 0)
		return (-1);
	return (value * k);
}

// int	ft_atoi(char *str)
// {
// 	int		i;
// 	long	res;
// 	int		sign;

// 	sign = 1;
// 	res = 0;
// 	i = 0;
// 	if (str[i] == '-')
// 		return (0);
// 	if (str[i] == '+')
// 		i++;
// 	while (!ft_isdigit(str[i++]))
// 		return (0);
// 	i = 0;
// 	while (ft_isdigit(str[i]))
// 	{
// 		res = (res * 10) + (str[i] - 48);
// 		i++;
// 		if ((res > 2147483647 && sign == 1))
// 			return (-1);
// 	}
// 	return (res * sign);
// }