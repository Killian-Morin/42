/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:18:52 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/24 09:39:42 by kmorin           ###   ########.fr       */
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

/*
	works witout this in the while(1) of checker_for_philos()
	replaced by an equivalent

void	infinite_loop(t_table *t, t_philo **philo)
{
	if (!(*philo))
		*philo = t->first_philo;
}
*/

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

/*
	For each philo/thread, join/wait for it to finish.
	If an error occur with the function, will writes the error, return to
	start_simulation() to free and return to the main to indicate the error.
	The message if all philo ate the sufficient amount of meals can be here.
*/
int	join_thread(t_table *t)
{
	t_philo	*philo;

	philo = t->first_philo;
	while (philo)
	{
		if (pthread_join(philo->thread, NULL) != 0)
		{
			printf("Error while waiting for a thread (pthread_join)\n");
			return (1);
		}
		philo = philo->next;
	}
	return (0);
}

int	start_simulation(t_table *t)
{
	if (t->nbr_philo == 1)
		simulation_for_one(t->first_philo);
	else
	{
		if (start_thread(t))
		{
			ft_free_all(t);
			return (1);
		}
		checker_for_philos(t);
		if (join_thread(t))
		{
			ft_free_all(t);
			return (1);
		}
	}
	return (0);
}
