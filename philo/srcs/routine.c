/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: killian <killian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:44:42 by kmorin            #+#    #+#             */
/*   Updated: 2023/06/13 16:07:26 by killian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
/*
	doing a simple usleep(time_to_wait * 1000) to convert to seconds
	is less precise than custom_sleep,
	there is always a little delay for the message died (02, 05 ...)
	but it is much smaller and easier
*/
void	cycle_for_one_philo(t_philo *philo)
{
	philo->state = TAKE_FORK;
	printf("%ld\t%d has taken a fork\n",
		get_time_pass(philo->time->start_time, get_time()), philo->id);
	custom_sleep(philo->time->die_time);
	philo_die(philo);
	ft_free(philo->table);
}

/*
	depending on the rank of the philo (even or not) sleep a bit or directly
	start the loop.
	in the loop, check if possible to do something: a philo is not already 
	dead, all philo did not eat all necessary meals to end the simulation or
	if the philo eat before the time_to_die.
	if all those conditions are filled then eat, sleep and think,
	else if even one of those conditions is not filled then break.
*/
void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		custom_sleep(philo->time->eat_time / 2);
	while (1)
	{
		if (philo->table->philo_dead == 0 && check_meals_reached(philo) == 1
			&& check_time_to_die_reached(philo) == 0)
		{
			philo_eat(philo);
			philo_sleep(philo);
			philo_think(philo);
		}
		else
			break ;
	}
	return (NULL);
}

int	checker_continue_routine(t_table *t)
{
	t_philo	*philo;

	philo = t->philo_prime;
	while (1)
	{
		if (check_time_to_die_reached(philo) == 1)
		{
			philo_die(philo);
			break ;
		}
		else if (all_meals_reached(t) == 0)
			break ;
		philo = philo->next;
		if (!philo)
			philo = t->philo_prime;
	}
	if (join_thread(t) == -1)
	{
		ft_free(t);
		return (-1);
	}
	return (0);
}
