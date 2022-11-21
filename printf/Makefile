NAME = libftprintf.a

SRCS = .c

OBJS = ${SRCS:.c=.o}

HEADER = printf.h

MAKE = make

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

.c.o: ${OBJS}
	${CC} ${CFLAGS} -c -I ${HEADER} $< -o ${:.c=.o}

${NAME}:	${OBJS}
	cd libft && ${MAKE} all
	arc rc libftprintf.a *.o

all:	${NAME}

clean:
	${RM} ${OBJS}

flcean:	clean
	${RM} ${NAME}

re: flcean all

.PHONY: all clean flcean all
