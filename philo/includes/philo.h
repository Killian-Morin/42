/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: killian <killian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:30:44 by kmorin            #+#    #+#             */
/*   Updated: 2023/06/12 14:49:00 by killian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define DEAD 0
# define EAT 1
# define SLEEP 2
# define THINK 3
# define TAKE_FORK 4

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

/*
memset, printf, malloc, free, write, usleep, gettimeofday
pthread_create, pthread_detach, pthread_join,
pthread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock,
pthread_mutex_unlock
*/

typedef struct s_time {
	int			die_time;
	int			eat_time;
	int			meal_to_eat;
	int			sleep_time;
	long int	start_time;
}				t_time;

typedef struct s_philo {
	int					id;
	int					state;
	int					meal_ate;
	long int			time_last_meal;
	pthread_t			thread;
	pthread_mutex_t		fork;
	pthread_mutex_t		*next_fork;
	t_time				*time;
	struct s_philo		*next;
	struct s_philo		*prev;
	struct s_table		*table;
}				t_philo;

typedef struct s_table {
	int		nbr_philo;
	int		philo_dead;
	t_time	*time;
	t_philo	*philo_prime;
}				t_table;

/*	main.c	*/
int			main(int ac, char **av);
int			check_args(int ac, char **av);
int			join_thread(t_table *t);

/*	init.c	*/
t_table		*init_table(char **av);
t_time		*init_time(int ac, char **av);
t_philo		*init_philo(t_table *t, int i);

/*	setup.c	*/
int			setup_each_philo(t_table *t);
void		setup_philo_around_table(t_table *t, t_philo *philo);
void		setup_fork_next(t_table *t);
int			setup_thread(t_table *t);

/*	routine.c	*/
void		*routine(void *philo);
void		cycle_for_one_philo(t_philo *philo);

/*	routine_utils.c	*/
int			check_time_to_die_reached(t_philo *philo);
int			check_meals_reached(t_philo *philo);

/*	action.c	*/
int			philo_take_fork(t_philo *philo, pthread_mutex_t *fork);
void		philo_eat(t_philo *philo);
void		philo_think(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		philo_die(t_philo *philo);

/*	time.c	*/
long int	get_time(void);
long int	get_time_pass(long int start, long int end);
void		custom_sleep(long int duration);

/*	utils.c	*/
int			ft_atoi(char *str);
void		ft_free(t_table *table);

#endif
