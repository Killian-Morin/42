NAME = minishell

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address
RM = rm -rf

LDFLAGS = -L $(HOME)/.brew/opt/readline/lib
CPPFLAGS = -I $(HOME)/.brew/opt/readline/include

INCLUDE = -I ./includes/ -I ./libft/
LIBRARIES = -Llibft -lft -lreadline
LIBFT = libft/libft.a

SRC_PATH = ./srcs/
SRC_FILES = builtin_cd.c \
			builtin_exit.c \
			builtin_export_second.c \
			builtin_export.c \
			builtin_functions.c \
			builtin_unset.c \
			builtin.c \
			clear.c \
			command_utils.c \
			command.c \
			env.c \
			error.c \
			execute_utils.c \
			execute.c \
			expansion_quotes.c \
			expansion_variable.c \
			expansion.c \
			heredoc_utils.c \
			heredoc.c \
			main.c \
			pipe.c \
			redirection.c \
			signal.c \
			termios.c \
			tokenizer_utils.c \
			tokenizer.c \
			utils_is.c \
			utils.c
			
SRCS = ${addprefix ${SRC_PATH}, ${SRC_FILES}}

OBJ_PATH = ./objs/
OBJ_FILES = ${SRC_FILES:.c=.o}
OBJS = ${addprefix ${OBJ_PATH}, ${OBJ_FILES}}

${OBJ_PATH}%.o:${SRC_PATH}%.c
	@(${CC} ${CFLAGS} ${INCLUDE} ${CPPFLAGS} -c $< -o $@)

all: ${OBJ_PATH} ${NAME}

${OBJ_PATH}:
	@mkdir ${OBJ_PATH}

${NAME}: ${LIBFT} ${OBJS}
	@echo "<---> Create objects <--->"
	@echo "<---> Create executable <--->"
	@(${CC} ${CFLAGS} ${INCLUDE} ${OBJS} ${LIBRARIES} ${LDFLAGS} ${CPPFLAGS} -o ${NAME})

${LIBFT}:
	@echo "<---> Compil libft <--->"
	@make -s -C ./libft

clean:
	@echo "<---> Clear objects <--->"
	@make -s -C ./libft clean
	@${RM} ${OBJ_PATH}

fclean: clean
	@echo "<---> Clear objects and executable <--->"
	@make -s -C ./libft fclean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
