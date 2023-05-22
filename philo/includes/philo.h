/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:30:44 by kmorin            #+#    #+#             */
/*   Updated: 2023/05/22 15:40:27 by kmorin           ###   ########.fr       */
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
	int			meal_to_eat;
	int			die_time;
	int			eat_time;
	int			sleep_time;
	long int	start_time;
}				t_time;

typedef struct s_philo {
	int			num;
	int			state;
	int			meal_status;
	long int	time_last_meal;
	t_time		*time;
	struct s_philo		*next;
	struct s_philo		*prev;
	struct s_table		*table;
}				t_philo;

typedef struct s_table {
	int		philo_dead;
	int		nbr_philo;
	t_time	*time;
	t_philo	*philo_prime;
}			t_table;

/*  main.c  */
int			main(int ac, char **av);
void		init_data(int ac, char **av, t_philo *p);
int			check_args(int ac, char **av);
long int	get_time(void);

/*  ft_atoi */
int			ft_atoi(char *str);

#endif
