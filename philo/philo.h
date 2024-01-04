/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalem < absalem@student.42abudhabi.ae    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:26:28 by absalem           #+#    #+#             */
/*   Updated: 2024/01/04 14:45:28 by absalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>
# include <limits.h>

# define ERROR_IR "invliad irgument"
# define MAX_NUM_PHILOSOPHERS 200
# define USAGE  "[philo_one number die eat s_sleep [eat]]\n"

typedef struct s_parameter
{
	int				number_of_philo;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				num_times_to_eat;
}					t_parameter;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	t_parameter		*parameter;

	int				is_eating;
	int				meals_eaten;
	size_t			last_meal_time;
	size_t			start_time;

	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;

	int				*dead_flag;
	pthread_mutex_t	*death_mutex;
	pthread_mutex_t	*meal_mutex;
	pthread_mutex_t	*output_mutex;
}					t_philo;

typedef struct s_program
{
	t_parameter		parameter;
	pthread_t		inspector_thread;
	t_philo			philos[MAX_NUM_PHILOSOPHERS];
	pthread_mutex_t	forks[MAX_NUM_PHILOSOPHERS];

	int				dead_flag;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	output_mutex;
}					t_program;


int parsing(int ac, char **av, t_parameter *parameter);




///////////////////////////   utiles ///////////////

void	ft_putstr_fd(char *s, int fd);
int	is_valid_number(char *str);
long	ft_atoi(char *str);
int check_input(int ac, char **av);

#endif