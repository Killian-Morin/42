NAME = cub3D

CC = gcc
CFLAGS = -Wall -Werror -Wextra #-g3 -fsanitize=address
RM = rm -rf

GREEN = \033[0;92m
WHITE = \033[0;97m
CYAN = \033[0;96m
MAGENTA = \033[0;95m

BONUS = 0

INCLUDE = -I ./includes/ -I ./libft/ -I ./mlx/
LIBFT = libft/libft.a
LIB_FLAG = -L ./libft -l ft

SRC_PATH = ./srcs/
SRC_FILES = bonus/collision.c \
			bonus/minimap_player.c \
			bonus/minimap.c \
			bonus/mouse.c \
			deplacement/mouvement.c \
			deplacement/rotation.c \
			parsing/colors.c \
			parsing/elements.c \
			parsing/empty_line.c \
			parsing/error.c \
			parsing/extract.c \
			parsing/map_check_utils.c \
			parsing/map_check_walls.c \
			parsing/map_check_walls2.c \
			parsing/map_check.c \
			parsing/parser.c \
			parsing/player.c \
			parsing/textures.c \
			parsing/utils.c \
			raycasting/floor_ceiling_casting.c \
			raycasting/init_textures.c \
			raycasting/texture_mapping.c \
			raycasting/wall_casting.c \
			keyboard.c \
			main.c \
			mlx.c \
			utils.c \

SRCS = ${addprefix ${SRC_PATH}, ${SRC_FILES}}

OBJ_PATH = ./objs/
OBJ_FILES = ${SRC_FILES:.c=.o}
OBJ = ${addprefix ${OBJ_PATH}, ${OBJ_FILES}}

DIR_DUP = @mkdir -p ${@D}

MLX_PATH = ./mlx/
MLX_MAKE =  ${addprefix ${MLX_PATH}, ./libmlx.a}
MLX_FLAG = -L ${MLX_PATH} -l mlx -framework OpenGL -framework AppKit

${OBJ_PATH}%.o:${SRC_PATH}%.c
	${DIR_DUP}
	@(${CC} ${CFLAGS} -D BONUS=${BONUS} ${INCLUDE} -c $< -o $@)

all: ${NAME}

${NAME}: ${LIBFT} ${MLX_MAKE} ${OBJ}
	@echo "${GREEN}\nCreate objects"
	@echo "${GREEN}Create executable (cub3D)\n${WHITE}"
	@(${CC} ${CFLAGS} ${INCLUDE} ${MLX_FLAG} -D BONUS=${BONUS} ${OBJ} ${LIB_FLAG} -lm -o ${NAME})

${LIBFT}:
	@echo "${GREEN}\nCompil libft\n"
	@make -s -C ./libft

${MLX_MAKE}:
	@echo "${GREEN}\nCompil mlx\n"
	@make -s -C ./mlx

bonus: fclean
	@echo "${MAGENTA}\nLaunch cub3d with BONUS${WHITE}"
	@make all BONUS=1

clean:
	@echo "${CYAN}Clear objects${WHITE}"
	@make -s -C ./libft clean
	@make -s -C ./mlx clean
	@${RM} ${OBJ_PATH}

fclean: clean
	@echo "${CYAN}Clear executable (cub3D)\n${WHITE}"
	@make -s -C ./libft fclean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
