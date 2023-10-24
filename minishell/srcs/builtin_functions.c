/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:35:25 by killian           #+#    #+#             */
/*   Updated: 2023/10/24 09:41:03 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_flag(char *str)
{
	int	i;

	i = 0;
	if (str[i] != '-' || (str[i] == '-' && str[i + 1] != 'n'))
		return (0);
	i++;
	while (str[i] == 'n')
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

int	ft_echo(char **cmd)
{
	int	i;
	int	option;

	i = 1;
	option = 0;
	while (cmd[i] && check_flag(cmd[i]))
	{
		option = 1;
		i++;
	}
	while (cmd[i])
	{
		printf("%s", cmd[i]);
		if (cmd[i + 1])
			printf(" ");
		i++;
	}
	if (!option)
		printf("\n");
	g_signal = 0;
	return (0);
}

int	ft_env(char **env)
{
	int	i;

	i = 0;
	while (i != get_size_env(env))
	{
		if (ft_strchr(env[i], '='))
			printf("%s\n", env[i]);
		i++;
	}
	return (0);
}

int	ft_pwd(void)
{
	char	*tmp;

	tmp = getcwd(NULL, 0);
	printf("%s\n", tmp);
	free(tmp);
	return (0);
}
