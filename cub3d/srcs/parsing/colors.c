/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:24:28 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/31 16:45:19 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_len_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	check_virgule(char *s, t_list *node, t_cub3d *data)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		if (s[i] == ',')
			nb++;
		i++;
	}
	if (nb != 2)
		parser_error_exit(node->content, "Not the right format.", data);
}

void	check_res_split(char **res, t_list *node, t_cub3d *data)
{
	int	i;
	int	j;

	if (!res[0] || !res[1] || !res[2] || get_len_tab(res) != 3)
		parser_error_exit(node->content, \
		"ft_split from get_int() failed. Check the format of the color.", data);
	i = -1;
	while (res[++i])
	{
		j = 0;
		while (res[i][j] && is_whitespace(res[i][j]))
			j++;
		if (!ft_isdigit(res[i][j]))
			parser_error_exit(node->content, \
			"Check the format of the color.", data);
		while (res[i][j] && ft_isdigit(res[i][j]))
			j++;
		while (res[i][j])
		{
			if (is_whitespace(res[i][j]) == false)
				parser_error_exit(node->content, \
				"Check the format of the color.", data);
			j++;
		}
	}
}

int	get_int(char *s, t_list *node, t_cub3d *data)
{
	char	**res;
	int		red;
	int		green;
	int		blue;

	while (is_whitespace(*s) == true)
		s++;
	check_virgule(s, node, data);
	res = ft_split(s, ',');
	check_res_split(res, node, data);
	red = ft_atoi(res[0]);
	if (red < 0 || red > 255)
		parser_error_exit(node->content, \
		"The red part of this color is out of range [0, 255].", data);
	green = ft_atoi(res[1]);
	if (green < 0 || green > 255)
		parser_error_exit(node->content, \
		"The green part of this color is out of range [0, 255].", data);
	blue = ft_atoi(res[2]);
	if (blue < 0 || blue > 255)
		parser_error_exit(node->content, \
		"The blue part of this color is out of range [0, 255].", data);
	free_tab(res);
	return ((red << 16 | green << 8 | blue));
}

bool	get_color(char *s, enum e_id key, t_list *node, t_cub3d *data)
{
	char	*value;

	check_multiple_declaration(key, node, data);
	value = ft_substr(s, find_start(s), ft_strlen(s));
	if (!value)
		parser_error_exit(node->content, "ft_substr from get_color() failed", \
			data);
	set_cond_flag(key, &data->cond);
	if (key == F)
		data->file.floor_color = get_int(s, node, data);
	else if (key == C)
		data->file.ceiling_color = get_int(s, node, data);
	free(value);
	return (true);
}
