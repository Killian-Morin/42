/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 08:06:32 by kmorin            #+#    #+#             */
/*   Updated: 2022/08/04 08:16:30 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i])
	{
		if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
		{
			ret = 1;
			i++;
		}
		else
			return (0);
	}
	return (ret);
}

int	main(int argc, char **argv)
{
	if (argc == 2 && argv[1])
		printf("%d\n", ft_str_is_alpha(argv[1]));
	return (0);
}
