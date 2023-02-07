/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:17:00 by kmorin            #+#    #+#             */
/*   Updated: 2023/01/09 11:17:10 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

/*
passe le type de retour en long int pour qu'il puisse gerer les int min & int max
*/
long int	ft_atoi(char *str)
{
	int			i;
	int			signe;
	long int	res;

	i = 0;
	res = 0;
	signe = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = signe * -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * signe);
}

/*
compare two strings
return the difference between the two elements that diverge
if there is no difference (the strings are identical) it return 0
*/
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_lstsize(t_stack *lst)
{
	int		i;
	t_stack	*temp;

	i = 0;
	if (lst == 0)
		return (i);
	temp = lst;
	while (temp != 0)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
