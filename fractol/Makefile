NAME = fractol

SRC_PATH = ./srcs/
SRC_FILES = julia.c keyboard.c main.c mandelbrot.c mouse.c utils.c color.c burningship.c
SRC = ${addprefix ${SRC_PATH}, ${SRC_FILES}}

OBJ_PATH = ./objs/
OBJ_FILES = ${SRC_FILES:.c=.o}
OBJ = ${addprefix ${OBJ_PATH}, ${OBJ_FILES}}

HEADER = ./includes/fractol.h

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

LIB_PATH = ./libft/
LIB_MAKE = ${addprefix ${LIB_PATH}, libft.a}
LIB_FLAG = -L ${LIB_PATH} -l ft

MLX_PATH = ./mlx/
MLX_MAKE = ${addprefix ${MLX_PATH}, mlx.a}
MLX_FLAG = -L ${MLX_PATH} -l mlx -framework OpenGL -framework AppKit

all: ${OBJ_PATH} ${LIB_MAKE} ${MLX_MAKE} ${NAME}

${OBJ_PATH}:
	mkdir ${OBJ_PATH}

${OBJ_PATH}%.o: ${SRC_PATH}%.c
	${CC} ${CFLAGS} -I ${MLX_PATH} -I ${LIB_PATH} -I ${HEADER} -o $@ -c $<

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

.PHONY: all re clean fclean