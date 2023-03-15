NAME = fractol

SRC_PATH = ./srcs/
SRC = main.c
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
	${CC} ${CFLAGS} -Imlx -Iincludes -c $< -o $@ 

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME}

clean:
	${RM} ${OBJ_PATH}

fclean: clean
	${RM} ${NAME}

re: fclean all

leaks: re
	leaks -atExit -- ${NAME}

.PHONY: all re clean fclean