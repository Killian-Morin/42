NAME = libftprintf.a

SRCS = ft_printf.c

OBJS = ${SRCS:.c=.o}

HEADER = ft_printf.h

MAKE =	make -C libft

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

.c.o:	${OBJS}
	${CC} ${CFLAGS} -c -I ${HEADER} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	${MAKE}
	cp libft/libft.a ./
	ar rc libftprintf.a *.o

all:	${NAME}

clean:
	${MAKE} clean
	${RM} ${OBJS}

fclean:	clean
	${MAKE} fclean
	${RM} ${NAME} libft.a

re: fclean all

.PHONY: all clean fclean all
