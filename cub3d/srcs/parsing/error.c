/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:34:55 by mdanchev          #+#    #+#             */
/*   Updated: 2023/10/27 15:12:34 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_msg_exit(char *s1, char *s2)
{
	ft_putstr_fd(RED "Error\n", 2);
	if (s1)
		ft_putstr_fd(s1, 2);
	if (s1 && s2)
		ft_putstr_fd(" ", 2);
	if (s2)
		ft_putstr_fd(s2, 2);
	ft_putstr_fd(WHITE "\n", 2);
	exit (1);
}

void	free_texture_file(t_file *file)
{
	if (file->no_tex)
		free(file->no_tex);
	if (file->so_tex)
		free(file->so_tex);
	if (file->ea_tex)
		free(file->ea_tex);
	if (file->we_tex)
		free(file->we_tex);
}

void	parser_error_exit(char *s1, char *s2, t_cub3d *data)
{
	free_texture_file(&data->file);
	ft_putstr_fd(RED "Error\n", 2);
	ft_putstr_fd("PARSER stopped at: ", 2);
	ft_putstr_fd(s1, 2);
	ft_putstr_fd("\nCause: ", 2);
	ft_putstr_fd(s2, 2);
	ft_putstr_fd(WHITE "\n", 2);
	exit (1);
}

/*
special free_tab that free all lines of the table whitin the range specified
then free this table
*/
void	free_tab_size(char **array, int size_y)
{
	int	i;

	i = 0;
	while (i <= size_y)
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}
