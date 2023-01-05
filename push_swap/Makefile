NAME = push_swap

SRCS =

OBJS = ${SRCS:.c=.o}

HEADER = push_swap.h

MAKE = make -C ft_printf

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

.c.o: ${OBJS}
	${CC} ${CFLAGS} -c -I {HEADER} $< -o ${<:c=.o}

all: ${OBJS}
	${MAKE}

clean:
	${MAKE} clean
	${RM} ${OBJS}

fclean: clean
	${MAKE} fclean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
