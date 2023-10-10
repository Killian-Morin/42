NAME = cub3D

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

INCLUDE = -I ./includes/ -I ./libft -I ./mlx
LIBFT = libft/libft.a
LIB_FLAG = -L ./libft -l ft

SRCS_PATH = ./srcs/
SRCS_FILES = test.c
SRCS = ${addprefix ${SRCS_PATH}, ${SRCS_FILES}}

OBJS_PATH = ./objs/
OBJ_FILES = ${SRCS_FILES:.c=.o}
OBJS = ${addprefix ${OBJS_PATH}, ${OBJ_FILES}}

MLX_PATH = ./mlx/
MLX_MAKE = ${addprefix ${MLX_PATH}, mlx.a}
MLX_FLAG = -L ${MLX_PATH} -l mlx -framework OpenGL -framework AppKit

all: ${OBJS_PATH} ${LIBFT} ${MLX_MAKE} ${NAME}

${OBJS_PATH}:
	@mkdir ${OBJS_PATH}

${OBJS_PATH}%.o:${SRCS_PATH}%.c
	@(${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@)

${LIBFT}:
	@echo "Compil libft"
	@make -s -C ./libft

${MLX_MAKE}:
	@make -s -C ${MLX_PATH}

${NAME}: ${OBJS}
	@echo "Create objects"
	@echo "Create executable (cub3D)"
	@(${CC} ${CFLAGS} ${MLX_FLAG} ${INCLUDE} ${OBJS} ${LIB_FLAG} -lm -o ${NAME})

clean:
	@echo "Clear objects"
	@make -s -C ./libft clean
	@make -s -C ./mlx clean
	@${RM} ${OBJS_PATH}

fclean: clean
	@echo "Clear executable (cub3D)"
	@make -s -C ./libft fclean
	@${RM} ${NAME}

re: fclean all

.PHONY: all fclean clean re
