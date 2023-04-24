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
	int		fd_infile;
	int		fd_outfile;
}		t_pipex;

/*
    main.c
*/
int			main(int argc, char **argv, char **env);
void		check_arg(int argc);

/*
	pipe.c
*/
void		init_fd(char **argv, t_pipex *p, char **env);
void		pipex(t_pipex *p, char **env);
void		child_processs(t_pipex *p, int end[2], char **env);
void		parent_process(t_pipex *p, int end[2], char **env);

#endif
