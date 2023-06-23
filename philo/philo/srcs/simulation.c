/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: killian <killian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:18:52 by kmorin            #+#    #+#             */
/*   Updated: 2023/06/23 15:39:36 by killian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
	printf the message for fork, then sleep for time needed to die,
	then printf the message to die.
	it will return to start_simulation(), that will return to the main,
	that will call ft_free_all and return 0.
*/
void	simulation_for_one(t_philo *philo)
{
	printf("%ld\t|%d|\thas taken a fork\n",
		get_time_pass(philo->table->start_time, get_time()), philo->id);
	custom_sleep(philo->table->die_time);
	printf("%ld\t|%d|\tdied\n",
		get_time_pass(philo->table->start_time, get_time()), philo->id);
}

void	start_simulation(t_table *t)
{
	if (t->nbr_philo == 1)
		simulation_for_one(t->first_philo);
	else
	{
		start_thread(t);
		checker_for_philos(t);
		join_thread(t);
	}
}

/*
	for the moment works witout this in the while(1) of checker_for_philos()
	is a bit of a equivalent

void	infinite_loop(t_table *t, t_philo **philo)
{
	if (!(*philo))
		*philo = t->first_philo;
}
*/

/*
	For each philo/thread, join/wait for it to finish.
	(If an error occur with the function, will writes the error, free all
	and return to the main that will return with an error.)
	The message if all philo ate the sufficient amount of meals can be here.
*/
void	join_thread(t_table *t)
{
	t_philo	*philo;

	philo = t->first_philo;
	while (philo)
	{
		pthread_join(philo->thread, NULL);
		philo = philo->next;
	}
}

/*
	check if need to stop the routine:
	if for a philo his last_meal is greater than time_to_die then die and break
	if all philos ate enough times check if its because they reached meal_to_eat
	(if it was specified) to print the message then break, 

	if not the case iterate to the next philo and if we are at the last philo
	we rebegin at the first philo.
*/
void	checker_for_philos(t_table *t)
{
	t_philo	*philo;

	philo = t->first_philo;
	while (1)
	{
		if (time_to_die_reached(philo))
		{
			philo_die(philo);
			break ;
		}
		else if (!meal_to_eat_reached(t))
		{
			if (t->meal_to_eat != -1)
				printf("Awesome ! All |%d| philosophers ate |%d| meals\n",
					t->nbr_philo, t->meal_to_eat);
			break ;
		}
		philo = philo->next;
		if (!philo)
			philo = t->first_philo;
	}
}
