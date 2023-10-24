/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 09:45:27 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/24 09:38:49 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_pipex {
	int		infile;
	int		outfile;
	int		fd[2];
	char	**my_paths;
	char	**cmd_arg;
	pid_t	pid_child1;
	pid_t	pid_child2;
}		t_pipex;

/*
    main.c
*/
int			main(int argc, char **argv, char **env);
void		check_arg(char **argv);

/*
	pipe.c
*/
void		init(t_pipex *p, char **argv, char **env);
void		pipex(t_pipex *p, char **argv, char **env);
void		child_one(t_pipex *p, char **env);
void		child_two(t_pipex *p, char **env);

/*
	errors.c
*/
void		error(char *str);
void		error_intermediate(t_pipex *p, char *str);
void		is_last_path(t_pipex *p, char *cmd, int i);

/*
	utils.c
*/
char		**get_paths(char **env);
void		clean(t_pipex *p);
void		clean_char_tab(char **str);
void		fd_close_all(t_pipex *p);
void		fd_close_two(int fd1, int fd2);

/*
	ft_split_path.c
	add a '/' at the end of each paths
*/
char		**ft_split_path(char const *s, char c);
char		**ft_fill_tab_path(char *src, char c, char **bigstr, int *len);
char		**ft_free_path(char **bigstr, int i, int *len);
int			*ft_cara_par_str_path(char *src, char c, int nbmot);
int			ft_countmot_path(char *src, char c);

#endif
