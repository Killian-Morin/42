NAME = push_swap

SRC_PATH = ./srcs/
SRC = push_swap.c action_push.c action_reverse_rotate.c action_rotate.c action_swap.c correct_input.c sort_small_stack.c sort_big_stack.c stack_manipulation.c utils.c sort.c
SRCS = ${addprefix ${SRCS_PATH}, ${SRC}}

OBJ_PATH = ./objs/
OBJ = ${SRC:.c=.o}
OBJS = ${addprefix ${OBJ_PATH}, ${OBJ}}

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

all: ${OBJ_PATH} ${NAME}

${OBJ_PATH}:
	mkdir ${OBJ_PATH}

${OBJ_PATH}%.o: ${SRC_PATH}%.c
	${CC} ${CFLAGS} -c $< -o $@ -I ./includes/

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	${RM} ${OBJ_PATH}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
