NAME = push_swap

SRCS = push_swap.c sort_small_stack.c sort_big_stack.c correct_input.c

OBJS = ${SRCS:.c=.o}

HEADER = push_swap.h

MAKE = make -C printf

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

.c.o: ${OBJS}
	${CC} ${CFLAGS} -c -I ${HEADER} $< -o ${<:.c=.o}

all: ${OBJS}
	${MAKE}
	${CC} ${CFLAGS} ${OBJS} ${HEADER} && ./${NAME}

clean:
	${MAKE} clean
	${RM} ${OBJS}

fclean: clean
	${MAKE} fclean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
