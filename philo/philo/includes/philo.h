/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:32:07 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/24 09:39:48 by kmorin           ###   ########.fr       */
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
	pthread_mutex_t		m_meal_ate;
	pthread_mutex_t		m_time_last_meal;
	pthread_mutex_t		m_fork;
	pthread_mutex_t		*m_next_fork;
	struct s_philo		*next;
	struct s_table		*table;
}				t_philo;

typedef struct s_table {
	int				nbr_philo;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				meal_to_eat;
	int				nbr_death;
	long int		start_time;
	t_philo			*first_philo;
	pthread_mutex_t	m_nbr_death;
}				t_table;

/* action.c */
int			philo_take_fork(t_philo *philo, pthread_mutex_t *fork);
void		philo_eat(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		philo_think(t_philo *philo);
void		philo_die(t_philo *philo);

/* cycle_utils.c */
int			can_make_action(t_philo *philo);
int			meal_to_eat_reached(t_table *t);
int			time_to_die_reached(t_philo *philo);

/* cycle.c */
int			start_thread(t_table *t);
void		*cycle(void *arg);

/* init.c */
t_philo		*init_philo(t_table *t, int i);
void		init_next_philo(t_table *t, t_philo *philo);
void		init_next_fork(t_table *t);
int			init_all_philo(t_table *t);
t_table		*init_table(int ac, char **av);

/* main.c */
int			check_args(int ac, char **av);
int			main(int ac, char **av);

/* simulation.c */
void		simulation_for_one(t_philo *philo);
void		checker_for_philos(t_table *t);
int			join_thread(t_table *t);
int			start_simulation(t_table *t);

/* time.c */
long int	get_time_pass(long int start, long int end);
long int	get_time(void);
void		custom_sleep(long int time_to_wait);

/* utils.c */
int			ft_atoi(char *str);
void		ft_free_all(t_table *t);

#endif