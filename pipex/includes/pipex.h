/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 09:45:27 by kmorin            #+#    #+#             */
/*   Updated: 2023/04/20 09:45:00 by kmorin           ###   ########.fr       */
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
	char	*path_env;
	char	**my_paths;
	char	**cmd_arg;
	pid_t	pid;
}		t_pipex;

/*
    main.c
*/
int			main(int argc, char **argv, char **env);
void		check_arg(char **argv);

/*
	pipe.c
*/
void		start(t_pipex *p, char **argv, char **env);
void		pipex(t_pipex *p, char **argv, char **env);
void		child_process(t_pipex *p, char **argv, char **env);
void		parent_process(t_pipex *p, char **argv, char **env);

/*
	utils.c
*/
void		get_path(t_pipex *p, char **env);
void		get_av(t_pipex *p, char **argv, int ac);
void		clean(t_pipex *p);

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
