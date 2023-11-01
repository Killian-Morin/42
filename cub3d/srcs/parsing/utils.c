/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:41:04 by mdanchev          #+#    #+#             */
/*   Updated: 2023/10/27 14:01:24 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_cond_flag(enum e_id key, t_cond *cond)
{
	if (key == NO)
		cond->no = 1;
	else if (key == SO)
		cond->so = 1;
	else if (key == WE)
		cond->we = 1;
	else if (key == EA)
		cond->ea = 1;
	else if (key == F)
		cond->f = 1;
	else if (key == C)
		cond->c = 1;
}

int	check_cond_flag(t_cond *cond)
{
	if (cond->no == 1 && cond->so == 1 && cond->we == 1 && cond->ea == 1 \
		&& cond->c == 1 && cond->f == 1)
		return (0);
	return (1);
}

int	find_start(char *s)
{
	int	i;

	i = 0;
	while (s[i] && is_whitespace(s[i]) == true)
		i++;
	return (i);
}

int	find_len(char *s, int i)
{
	int	len;

	len = 0;
	while (s[i] && is_whitespace(s[i]) == false)
	{
		i++;
		len++;
	}
	return (len);
}
