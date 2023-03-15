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

MLX_MAKE = make -C mlx

all: ${OBJ_PATH} ${NAME}

${OBJ_PATH}:
	mkdir ${OBJ_PATH}

${OBJ_PATH}%.o: ${SRC_PATH}%.c
	${CC} ${CFLAGS} -Imlx -I ./includes -c $< -o $@ 

${NAME}: ${OBJS}
	${MLX_MAKE}
	${CC} ${CFLAGS} ${OBJS} -Lmlx -framework OpenGL -framework AppKit -o ${NAME}

clean:
	${MLX_MAKE} clean
	${RM} ${OBJ_PATH}

fclean: clean
	${MLX_MAKE} fclean
	${RM} ${NAME}

re: fclean all

leaks: re
	leaks -atExit -- ${NAME}

.PHONY: all re clean fclean leaks