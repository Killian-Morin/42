NAME = libftprintf.a

SRCS = ft_int.c

OBJS = ${SRCS:.c=.o}

HEADER = libft_printf.h

MAKE =	make -C libft

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

.c.o:	${OBJS}
	${CC} ${CFLAGS} -c -I ${HEADER} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	${MAKE}
	ar rc libftprintf.a *.o

all:	${NAME}

clean:
	${MAKE} clean
	${RM} ${OBJS}

fclean:	clean
	${MAKE} fclean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean all
