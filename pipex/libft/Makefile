NAME = libft.a

SRC = ft_putstr_fd.c ft_strnstr.c ft_strlen.c ft_strncmp.c

HEADER = libft.h

OBJ = ${SRC:.c=.o}

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

.c.o: ${OBJS}
	${CC} ${CFLAGS} -I ${HEADER} -c $< -o $@

${NAME}: ${OBJ}
	ar rc libft.a *.o

all: ${NAME}

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
