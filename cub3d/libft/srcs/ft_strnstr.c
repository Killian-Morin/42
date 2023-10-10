/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:29:51 by kmorin            #+#    #+#             */
/*   Updated: 2023/09/07 11:23:07 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (i < len && i < ft_strlen(haystack))
	{
		k = 0;
		while (haystack[i] == needle[k] && (i < len
				&& i < ft_strlen(haystack) && k < ft_strlen(needle)))
		{
				k++;
				i++;
		}
		i = i - k;
		if (k == ft_strlen(needle))
			return ((char *)&haystack[i]);
		i++;
	}
	return (0);
}
