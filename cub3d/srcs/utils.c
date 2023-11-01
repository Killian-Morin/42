/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:04:31 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/31 09:11:14 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	free all lines of a malloc table, then free this table
*/
void	free_tab(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
}

/*
	print a custom message depending on the situation provided
	free all that needs to be freed
	exit with the exit code provided (since some cases are success or failure)
*/
void	exit_routine(t_cub3d *data, int msg_nb, int exit_code)
{
	if (msg_nb == 0)
		printf(PURPLE "Exited the labyrinth with the red cross\n" WHITE);
	else if (msg_nb == 1)
		printf(PURPLE "Exited the labyrinth with the ESC key\n" WHITE);
	else if (msg_nb == 2)
		ft_putstr_fd(RED "Error when using the mlx function\n" WHITE, 2);
	else if (msg_nb == 3)
		printf(PURPLE "Exited the labyrinth, the player went out of it\n" WHITE);
	else if (msg_nb == 4)
		printf(RED "Error when putting one of the texture to the image\n" WHITE);
	free_texture_file(&data->file);
	free_tab_size(data->file.map, data->file.map_max_y);
	free(data->t);
	exit(exit_code);
}

void	error_exit(char *s, int exit_code)
{
	ft_putstr_fd(RED "Error\n", 2);
	ft_putstr_fd(s, 2);
	exit(exit_code);
}

void	explanation_text(void)
{
	ft_putstr_fd(YELLOW "/---------------------------------------\\\n", 1);
	ft_putstr_fd("|       W, A, S, D to move around       |\n", 1);
	ft_putstr_fd("|          -> and <- to rotate          |\n", 1);
	ft_putstr_fd("|          P to show the mouse          |\n", 1);
	ft_putstr_fd("|          H to hide the mouse          |\n", 1);
	ft_putstr_fd("|       M to lock/unlock the mouse      |\n", 1);
	ft_putstr_fd("|          R to reset the game          |\n", 1);
	ft_putstr_fd("|  ESC or red cross to escape the game  |\n", 1);
	ft_putstr_fd("|                 glhf                  |\n", 1);
	ft_putstr_fd("\\---------------------------------------/\n\n" WHITE, 1);
}
