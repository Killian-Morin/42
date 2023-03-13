NAME = fractol

SRC_PATH = ./srcs/
SRC = 
SRCS = ${addprefix ${SRCS_PATH}, ${SRC}}

OBJ_PATH = ./objs/
OBJ = 
OBJS = ${addprefix ${OBJ_PATH}, ${OBJ}}

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

all: ${OBJ_PATH} ${NAME}

${OBJ_PATH}:
	mkdir ${OBJ_PATH}

${OBJ_PATH}%.o: ${SRC_PATH}%.c
	${CC} ${CFLAGS} -Imlx -c $< -o $@ -I ./includes/

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME}

clean:
	${RM} ${OBJS_PATH}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all re clean fclean