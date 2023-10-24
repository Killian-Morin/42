/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:43:11 by killian           #+#    #+#             */
/*   Updated: 2023/10/24 09:41:15 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
recupère le nb de variables parmis les variables d'environnement
(compte pas dernière ligne = NULL)
*/
int	get_size_env(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*
recupère l'index de la var passée en arg parmis les variables d'environnements
*/
int	get_variable_index_env(char **env, char *var)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], var, ft_strlen(var)))
			return (i);
		i++;
	}
	return (i);
}

/*
recupère la valeur de la var passée en arg parmis les variables d'environnements
pour ne pas avoir le = dans le résultat
il faut le mettre à la fin de la var quand on appel
*/
char	*get_variable_env(char **env, char *var)
{
	char	*tmp;
	int		i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], var, ft_strlen(var)))
		{
			tmp = ft_strtrim(env[i], var);
			return (tmp);
		}
		i++;
	}
	return (NULL);
}

/*
copie toutes les variables d'environnements
*/
char	**get_env(char **env, int env_size)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = malloc(sizeof(char *) * (env_size + 1));
	if (!tmp)
		return (NULL);
	while (i != env_size)
	{
		tmp[i] = ft_strdup(env[i]);
		if (!ft_strncmp(tmp[i], "SHLVL=", 6))
			tmp[i][6] += 1;
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}
