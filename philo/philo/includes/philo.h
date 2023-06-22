/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:32:07 by kmorin            #+#    #+#             */
/*   Updated: 2023/06/22 15:53:07 by kmorin           ###   ########.fr       */
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

/* main.c */
int			check_args(int ac, char **av);
int			main(int ac, char **av);

/* init.c */
t_philo		*init_philo(t_table *t, int i);
void		init_next_philo(t_table *t, t_philo *philo);
void		init_next_fork(t_table *t);
int			init_all_philo(t_table *t);
t_table		*init_table(int ac, char **av);

/* utils.c */
int			ft_atoi(char *str);
void		ft_free_all(t_table *t);
void		ft_free_for_one(t_table *t);

/* time.c */
long int	get_time_pass(long int start, long int end);
long int	get_time(void);
void		custom_sleep(long int time_to_wait);

/* simulation.c */
void		simulation_for_one(t_philo *philo);
void		start_simulation(t_table *t);
void		infinite_loop(t_table *t, t_philo **philo);
void		join_thread(t_table *t);
void		checker_for_philos(t_table *t);

/* cycle.c */
void		start_thread(t_table *t);
void		*cycle(void *arg);

/* cycle_utils.c */
int			can_make_action(t_philo *philo);
int			check_meal_to_eat_reached(t_table *t);
int			time_to_die_reached(t_philo *philo);

/* action.c */
int			philo_take_fork(t_philo *philo, pthread_mutex_t *fork);
void		philo_eat(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		philo_think(t_philo *philo);
void		philo_die(t_philo *philo);

#endif