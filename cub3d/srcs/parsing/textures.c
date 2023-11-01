/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:27:45 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/27 14:02:59 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_value_texture(char *file_name, enum e_id key, t_cub3d *data)
{
	if (key == NO)
		data->file.no_tex = ft_strdup(file_name);
	else if (key == SO)
		data->file.so_tex = ft_strdup(file_name);
	else if (key == WE)
		data->file.we_tex = ft_strdup(file_name);
	else if (key == EA)
		data->file.ea_tex = ft_strdup(file_name);
}

bool	get_texture_file(char *s, enum e_id key, t_list *node, t_cub3d *data)
{
	int		fd;
	char	*file;

	check_multiple_declaration(key, node, data);
	file = ft_substr(s, find_start(s), ft_strlen(s));
	if (!file)
		error_exit("ft_substr from get_texture_file failed\n", 1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		free(file);
		parser_error_exit(node->content, strerror(errno), data);
	}
	close(fd);
	set_cond_flag(key, &data->cond);
	set_value_texture(file, key, data);
	free(file);
	return (true);
}
