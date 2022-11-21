/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:22:09 by kmorin            #+#    #+#             */
/*   Updated: 2022/11/02 10:41:07 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char	*ft_strdup(const char *src)
{
	char	*str;
	char	*temp;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (temp == NULL)
		return (NULL);
	str = temp;
	while (i != len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	main(void)
{
	const char	*s = "salutations";

	printf("%s\n", ft_strdup(s));
	printf("%s\n", strdup(s));
	return (0);
}
