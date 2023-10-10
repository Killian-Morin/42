/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:55:57 by kmorin            #+#    #+#             */
/*   Updated: 2023/09/07 11:23:12 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_find_start(char const *s1, char const *set)
{
	int	i;
	int	start;

	i = 0;
	start = 0;
	while (set[i] && s1[start])
	{
		if (set[i] == s1[start])
		{
			start++;
			i = 0;
		}
		else
			i++;
	}
	return (start);
}

int	ft_find_end(char const *s1, char const *set)
{
	int	i;
	int	end;

	i = 0;
	end = ft_strlen(s1) - 1;
	while (set[i] && end >= 0)
	{
		if (set[i] == s1[end])
		{
			end--;
			i = 0;
		}
		else
			i++;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;

	if (s1 == NULL && set == NULL)
		return (NULL);
	start = ft_find_start(s1, set);
	end = ft_find_end(s1, set);
	str = ft_substr(s1, start, (end - start) + 1);
	return (str);
}
