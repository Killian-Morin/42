/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:30:44 by kmorin            #+#    #+#             */
/*   Updated: 2023/06/15 11:19:48 by kmorin           ###   ########.fr       */
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

typedef struct s_philo {
	int					id;
	int					meal_ate;
	long int			time_last_meal;
	pthread_t			thread;
	pthread_mutex_t		fork;
	pthread_mutex_t		*next_fork;
	struct s_philo		*next;
	struct s_table		*table;
}				t_philo;

typedef struct s_table {
	int			nbr_philo;
	int			philo_dead;
	int			meal_to_eat;
	int			die_time;
	int			eat_time;
	int			sleep_time;
	long int	start_time;
	t_philo		*philo_prime;
}				t_table;

/*	main.c	*/
int			join_thread(t_table *t);
int			check_args(int ac, char **av);
int			main(int ac, char **av);

/*	init.c	*/
t_philo		*init_philo(t_table *t, int i);
t_table		*init_table(int ac, char **av);

/*	setup.c	*/
int			setup_thread(t_table *t);
void		setup_fork_next(t_table *t);
void		setup_philo_around_table(t_table *t, t_philo *philo);
int			setup_each_philo(t_table *t);

/*	routine.c	*/
void		case_for_one_philo(t_philo *philo);
void		*routine(void *philo);
void		checker_end_of_routine(t_table *t);

/*	routine_utils.c	*/
int			check_time_to_die_reached(t_philo *philo);
int			check_meals_reached(t_philo *philo);
int			all_philo_ate_enough(t_table *table);
int			check_can_make_action(t_philo *philo);

/*	action.c	*/
int			philo_take_fork(t_philo *philo, pthread_mutex_t *fork);
void		philo_eat(t_philo *philo);
void		philo_think(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		philo_die(t_philo *philo);

/*	time.c	*/
long int	get_time_pass(long int start, long int end);
long int	get_time(void);
void		custom_sleep(long int duration);

/*	utils.c	*/
int			ft_atoi(char *str);
void		ft_free_all(t_table *table);

#endif
