NAME = philo

SRC_PATH = ./srcs/
SRC_FILES = main.c \
			init.c \
			utils.c \
			time.c \
			simulation.c \
			cycle.c \
			cycle_utils.c \
			action.c \

SRC = ${addprefix ${SRC_PATH}, ${SRC_FILES}}

OBJ_PATH = ./objs/
OBJ_FILES = ${SRC_FILES:.c=.o}
OBJ = ${addprefix ${OBJ_PATH}, ${OBJ_FILES}}

HEADER = ./includes/philo.h

CC = gcc
CFLAGS = -Wall -Werror -Wextra -pthread -fsanitize=thread
RM = rm -rf

all: ${OBJ_PATH} ${NAME}

${OBJ_PATH}:
	mkdir ${OBJ_PATH}

${OBJ_PATH}%.o: ${SRC_PATH}%.c
	${CC} ${CFLAGS} -I ${HEADER} -o $@ -c $<

${NAME}: ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME}

clean:
	${RM} ${OBJ_PATH}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
