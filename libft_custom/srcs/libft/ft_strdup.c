/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:33:11 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/12 15:24:33 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strdup(const char *src)
{
	size_t		i;
	char		*str;
	char		*temp;

	temp = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (temp == NULL)
		return (0);
	i = 0;
	str = temp;
	while (i != ft_strlen(src))
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
