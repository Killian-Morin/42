NAME = libft.a

SRC = ./src/

SRCS = ${SRC}ft_putchar.c ${SRC}ft_swap.c ${SRC}ft_putstr.c ${SRC}ft_strcmp.c ${SRC}ft_strlen.c

OBJS = ${SRCS:.c=.o}

INCLUDE = ./includes/

RM = rm -f
CFLAG = -Wall -Wextra -Werror

.c.o:
	gcc ${CFLAG} -c -I ${INCLUDE} $< -o ${<:.c=.o}

all:	${NAME}

${NAME}:	${OBJS}
	ar rc ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all
