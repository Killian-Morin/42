NAME = libft.a

SRC_PATH = ./srcs/
SRC_FILES = ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \
			get_next_line.c \
			get_next_line_utils.c \

SRCS = ${addprefix ${SRC_PATH}, ${SRC_FILES}}

OBJ_PATH = ./objs/
OBJ_FILES = ${SRC_FILES:.c=.o}
OBJS = ${addprefix ${OBJ_PATH}, ${OBJ_FILES}}

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: ${OBJ_PATH} ${NAME}

${OBJ_PATH}:
	@mkdir ${OBJ_PATH}

${OBJ_PATH}%.o:${SRC_PATH}%.c
	${CC} ${CFLAGS} -o $@ -c $<

${NAME}:	${OBJS}
	ar rc ${NAME} ${OBJS}

clean:
	${RM} ${OBJ_PATH}

fclean:	clean
	${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re
