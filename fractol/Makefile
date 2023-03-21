NAME = fractol

SRC_PATH = ./srcs/
SRC_FILES = main.c keyboard.c
SRC = ${addprefix ${SRC_PATH}, ${SRC_FILES}}

OBJ_PATH = ./objs/
OBJ_FILES = ${SRC_FILES:.c=.o}
OBJ = ${addprefix ${OBJ_PATH}, ${OBJ_FILES}}

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

LIB_PATH = ./libft/
LIB_MAKE = ${addprefix ${LIB_PATH}, libft.a}
LIB_FLAG = -L ${LIB_PATH} -l ft -l pthread

MLX_PATH = ./mlx/
MLX_MAKE = ${addprefix ${MLX_PATH}, mlx.a}
MLX_FLAG = -L ${MLX_PATH} -l mlx -framework OpenGL -framework AppKit

all: ${OBJ_PATH} ${LIB_MAKE} ${MLX_MAKE} ${NAME}

${OBJ_PATH}:
	mkdir ${OBJ_PATH}

${OBJ_PATH}%.o: ${SRC_PATH}%.c
	${CC} ${CFLAGS} -I ${MLX_PATH} -I ${LIB_PATH} -I ./includes -o $@ -c $<

${LIB_MAKE}:
	@make -C ${LIB_PATH}

${MLX_MAKE}:
	@make -C ${MLX_PATH}

${NAME}: ${OBJ}
	${CC} ${CFLAGS} ${OBJ} ${MLX_FLAG} ${LIB_FLAG} -lm -o ${NAME}

clean:
	${RM} ${OBJ_PATH}
	make -C ${LIB_PATH} clean
	make -C ${MLX_PATH} clean

fclean: clean
	${RM} ${NAME}
	make -C ${LIB_PATH} fclean

re: fclean all

leaks: re
	leaks -atExit -- ./${NAME}

.PHONY: all re clean fclean leaks