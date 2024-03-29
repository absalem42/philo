/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalem < absalem@student.42abudhabi.ae    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:26:28 by absalem           #+#    #+#             */
/*   Updated: 2024/02/03 11:13:57 by absalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "philo.h"
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define ERROR_IR "invliad irgument"
# define MAX_NUM_PHILOSOPHERS 200
# define USAGE "[philo_one number die eat s_sleep [eat]]\n"

typedef struct s_params
{
	int				num_of_philos;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				num_times_to_eat;
}					t_params;

typedef struct s_philo
{
	t_params		*params;
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			start_time;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}					t_philo;

typedef struct s_program
{
	pthread_mutex_t	forks[MAX_NUM_PHILOSOPHERS];
	t_philo			philos[MAX_NUM_PHILOSOPHERS];
	t_params		params;
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
}					t_program;

///////////////////////////    ///////////////

int					parsing(int ac, char **av, t_params *parameter);
int					program_input(int ac, char **av);
void				philo_init(t_program *program);
void				mutex_init(t_program *program, t_params *params);
void				init_philo(t_program *program, t_params *params);
void				init_thread(t_philo *philos, t_program *program);
void				destroy_mutexes(t_program *program);
void				thread_creat(t_philo *philos);
void				join_thread(t_philo *philos);
void				death(t_philo *philo);
int					philosophers_are_not_alive(t_philo *philo);
int					check_time_of_death(t_philo *philo);
int					check_done_eat(t_philo *philo);
void				obeserv(t_philo *philos);
void				*routine(void *arg);
void				eating_philo(t_philo *philo);

/////////////////////////////   utiles ///////////////
void				ft_putstr_fd(char *s, int fd);
int					is_valid_number(char *str);
int					check_input(int ac, char **av);
int					ft_usleep(size_t milliseconds, t_philo *philo);
long long			get_time(void);
int					ft_atoi(char *str);
void				print_message(t_philo *philo, char *message);

#endif