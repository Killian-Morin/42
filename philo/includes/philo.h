/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:30:44 by kmorin            #+#    #+#             */
/*   Updated: 2023/05/23 15:42:17 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

/*
memset, printf, malloc, free, write, usleep, gettimeofday
pthread_create, pthread_detach, pthread_join,
pthread_mutex_init, pthread_mutex_destroy,pthread_mutex_lock,
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
	int					num;
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

/*  main.c  */
int			main(int ac, char **av);
int			check_args(int ac, char **av);

/*	init.c	*/
t_table		*init_table(char **av);
t_time		*init_time(int ac, char **av);
void		philo_spawn(t_table *t);
t_philo		*init_philo(t_table *t, int i);
void		philo_sit_at_table(t_table *t, t_philo *philo);

/*  utils.c */
int			ft_atoi(char *str);
long int	get_time(void);

#endif
