/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:44:42 by kmorin            #+#    #+#             */
/*   Updated: 2023/06/15 10:51:09 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
/*
	printf the message for fork, then sleep for time needed to die,
	then killing the philo and free all.
*/
void	cycle_for_one_philo(t_philo *philo)
{
	printf("%ld\t%d has taken a fork\n",
		get_time_pass(philo->time->start_time, get_time()), philo->id);
	custom_sleep(philo->time->die_time);
	philo_die(philo);
	ft_free_all(philo->table);
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
		if (check_can_make_action(philo))
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

/*
	check if need to stop the routine:
	if for a philo his last_meal is greater than time_to_die then die and break
	if all philos ate enough times break, the custom message will be print later

	if not the case check the next philo and if we are at the end of the philo
	we rebegin at the first philo.
*/
void	checker_end_of_routine(t_table *t)
{
	t_philo	*philo;

	philo = t->philo_prime;
	while (1)
	{
		if (check_time_to_die_reached(philo))
		{
			philo_die(philo);
			break ;
		}
		else if (all_philo_ate_enough(t))
			break ;
		philo = philo->next;
		if (philo == NULL)
			philo = t->philo_prime;
	}
}
