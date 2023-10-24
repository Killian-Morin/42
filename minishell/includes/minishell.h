/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:17:05 by killian           #+#    #+#             */
/*   Updated: 2023/10/24 09:40:54 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include <signal.h>
# include <limits.h>
# include <termios.h>
# include <fcntl.h>
# include <string.h>
# include <curses.h>
# include <term.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <dirent.h>
# include <sysexits.h>

# include "../libft/includes/libft.h"

# define ERR_PARSER 257

int	g_signal;

typedef enum e_token_type {
	REDIR_IN,
	REDIR_OUT,
	HERE_DOC,
	REDIR_OUT_APPEND,
	PIPE,
	QUOTE_STR,
	DBL_QUOTE_STR,
	LITERAL,
	IGNORE
}	t_token_type;

typedef struct s_token {
	char			*content;
	t_token_type	type;
	struct s_token	*next;
}	t_token;

typedef struct s_redirection {
	char					*file_name;
	int						append;
	struct s_redirection	*next;
}	t_redirection;

typedef struct s_command {
	int				infile_fd;
	int				outfile_fd;
	int				fd[2];
	char			*path;
	char			**full_cmd;
	pid_t			pid;
	t_redirection	*infile;
	t_redirection	*outfile;
}	t_command;

typedef struct s_data {
	int					cmd_nbr;
	int					previous_fd[2];
	char				*user_input;
	char				**envp;
	t_command			*commands;
	t_token				*tok;
	struct sigaction	sig_old;
}					t_data;

//builtin_cd.c
void			update_env(t_data *data, char *var, char *new_value);
void			ft_no_path(t_data *data);
void			ft_to_oldpwd(t_data *data);
void			ft_path(t_data *data, char *directory);
int				ft_cd(t_data *data, char *directory);

//builtin_exit.c
void			exit_error_numeric(t_data *data, char *s);
void			check_valid_arg(t_data *data, char *s);
int				ft_exit(t_data *data, int i);

//builtin_export_second.c
int				ft_strcmp(char *s1, char *s2);
char			**alpha_sort_tab(char **env);
int				ft_export_no_arg(char **env);

//builtin_export.c
size_t			ft_strchr_index(const char *str, int c);
char			**ft_new_export(t_data *data, char *var_name, char *new_value);
int				ft_export(t_data *data, char *cmd);

//builtin_functions.c
int				check_flag(char *str);
int				ft_echo(char **cmd);
int				ft_env(char **env);
int				ft_pwd(void);

//builtin_unset.c
char			**ft_adjust_unset(t_data *data, int index_var);
int				ft_unset(t_data *data, int i);

//builtin.c
int				is_a_builtin(char **cmd);
int				which_builtin(t_data *data, int i);
void			restore_redirections_builtin(t_data *data);
int				exec_one_builtin(t_data *data);

//clear.c
void			free_strs_table(char **tmp);
void			clear_redirection(t_redirection *cur);
void			clear_all_commands(t_command *commands, int cmd_nbr);
void			reset_after_exec_cmd(t_data *data);

//command_utils.c
void			add_info_redir(t_redirection **file, char *name, int append);
int				get_redirections(t_token *tok, t_command *cur_command);
t_token			*manage_redirections(t_token *tok, t_command *cur_command);
t_token			*get_strings(t_token *tok, t_command *cur_command);
t_token			*manage_strings(t_token *tok, t_command *cur_command);

//command.c
t_token			*parse_one_command(t_command *cmd, t_token *tok);
void			parse_commands(t_command *cmds, t_token *tok, int cmd_nbr);
t_command		*init_commands(t_token *tok, int cmd_nbr);

//env.c
int				get_size_env(char **str);
int				get_variable_index_env(char **env, char *var);
char			*get_variable_env(char **env, char *var);
char			**get_env(char **env, int env_size);

//error.c
void			exit_error(char *msg, char *command, int code);
void			print_error(char *msg, char *command);

//execute_utils.c
char			**get_paths(char **env);
void			check_valid_path(char *path);
char			*create_path(char *path, char *cmd);
char			*check_all_paths(char **path, char *cmd);
char			*get_path_for_command(t_data *data, int i);

// execute.c
void			children(t_data *data, int i);
void			do_for_each_cmd(t_data *data, int i);
void			exec_loop(t_data *data);
int				execute(t_data *data);

//expansion_quotes.c
int				get_quotes_nb(char *s);
int				check_valid_quotes(char *s);
char			*deletion_of_quotes(char *s, char *new);
char			*delete_quotes(char *s);

//expansion_variable.c
char			*get_variable_env_expansion(char **env, char *var);
int				get_end_env_var(char *str, int in_quote);
char			*get_env_var(char **env, char *str, int end);
int				expand_env_var(char **env, char **str, int pos, int in_quote);

//expansion.c
void			check_for_quotes(char **env, char **str);
char			*expansion_tilde_home(char *str, char **env);
t_token			*expansion(t_token *tok, char **env);
int				expansion_manager(t_token *tok, char **env);

//heredoc_utils.c
void			child_loop(int fd, int expand, char *delimiter, t_data *data);
void			heredoc_child(int fd, int expand, char *delim, t_data *data);
int				heredoc_parent(t_data *data, pid_t pid);
void			unlink_heredoc(t_data *data, int i);
void			heredoc_signal(void);

//heredoc.c
int				prepare_execute_heredoc(char *delimiter);
int				execute_heredoc(int fd, char *delimiter, t_data *data);
int				init_heredoc(t_data *d, t_redirection *r, t_command *c, int i);
int				heredoc(t_data *data);

//main.c
void			loop(t_data *data);
int				main(int ac, char **av, char **env);

//pipe.c
void			ft_redirection_pipe(t_data *data, int i);
void			close_all_pipes(t_data *data, int i);

//redirection.c
int				in_redirection(t_command *cmd);
int				create_out_file(t_command *cmd, t_redirection *previous);
int				out_redirection(t_command *cmd);
void			close_redirections(t_command *cmd);

//signal.c
void			handler_sigint(int i);
void			handler_sigquit(int i);
void			manage_sig(t_data *data);
void			restore_sig(t_data *data);
void			ignore_sig(void);

//termios.c
void			disable_print_termios(void);
void			enable_print_termios(void);

//tokenizer_utils.c
t_token			*create_token(char *content, t_token_type type);
void			add_token(t_token **tokens, t_token *new);
t_token_type	quote_type(char c);
int				number_of_commands(t_token *tok);
void			clear_tokens(t_token *tok);

//tokenizer.c
int				extract_literal(t_token **tokens, char *user_input);
int				extract_quote_string(t_token **tokens, char *user_input);
int				extract_redir(t_token **tokens, char *user_input);
int				extract_tokens(t_token **tok, char *user_input);
t_token			*tokenizer(char *input);

//utils_is.c
int				is_quote(char c);
int				is_space(int c);
int				is_sep(int c);
int				is_redir(t_token_type type);
int				is_string(t_token_type type);

//utils.c
void			text_start(void);
void			cmd_to_lower(char **str);
void			check_status(int status);
int				size_of_command(t_token *tok);

#endif
