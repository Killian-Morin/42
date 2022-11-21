/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:01:47 by kmorin            #+#    #+#             */
/*   Updated: 2022/10/26 17:18:47 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	k;

	i = 0;
	if (to_find[i] == '\0')
		return (str);
	while (str[i])
	{
		k = 0;
		while (to_find[k] == str[i + k])
		{
			if (to_find[k + 1] == '\0')
				return (str + i);
			else
				k++;
		}
		i++;
	}
	return (0);
}

int	main(void)
{
	char	*str;
	char	*to_find;

	str = "hello, hey, yeah";
	to_find = "hey";
	printf("%s\n", ft_strstr(str, to_find));
	printf("%s\n", strstr(str, to_find));
}
