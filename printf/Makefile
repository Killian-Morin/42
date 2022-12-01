NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_gestion_divers.c ft_printf_gestion_hex.c ft_printf_gestion_int.c ft_printf_gestion_ptr.c

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
	ar rc libftprintf.a *.o libft/*.o

all:	${NAME}

clean:
	${MAKE} clean
	${RM} ${OBJS}

fclean:	clean
	${MAKE} fclean
	${RM} ${NAME} libft.a

re: fclean all

.PHONY: all clean fclean all
