NAME = pipex

SRC_PATH = ./srcs/
SRC_FILES = main.c pipe.c utils.c ft_split_path.c errors.c
SRC = ${addprefix ${SRC_PATH}, ${SRC_FILES}}

OBJ_PATH = ./objs/
OBJ_FILES = ${SRC_FILES:.c=.o}
OBJ = ${addprefix ${OBJ_PATH}, ${OBJ_FILES}}

HEADER = ./includes/pipex.h

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

LIB_PATH = ./libft/
LIB_MAKE = ${addprefix ${LIB_PATH}, libft.a}
LIB_FLAG = -L ${LIB_PATH} -l ft

all: ${OBJ_PATH} ${LIB_MAKE} ${NAME}

${OBJ_PATH}:
	mkdir ${OBJ_PATH}

${OBJ_PATH}%.o: ${SRC_PATH}%.c
	${CC} ${CFLAGS} -I ${LIB_PATH} -I ${HEADER} -o $@ -c $<

${LIB_MAKE}:
	@make -C ${LIB_PATH}

${NAME}: ${OBJ}
	${CC} ${CFLAGS} ${OBJ} ${LIB_FLAG} -lm -o ${NAME}

clean:
	${RM} ${OBJ_PATH}
	make -C ${LIB_PATH} clean

fclean: clean
	${RM} ${NAME}
	make -C ${LIB_PATH} fclean

re: fclean all

.PHONY: all re clean fclean