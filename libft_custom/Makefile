NAME = libft.a

SRC_PATH = ./srcs/
SRC_FILES = ft_printf/ft_dprintf.c \
			ft_printf/ft_printf.c \
			ft_printf/ft_printf_gestion_divers.c \
			ft_printf/ft_printf_gestion_hex.c \
			ft_printf/ft_printf_gestion_int.c \
			ft_printf/ft_printf_gestion_ptr.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c \
			get_next_line/get_next_line_bonus.c \
			get_next_line/get_next_line_utils_bonus.c \
			libft/ft_atoi.c \
			libft/ft_bzero.c \
			libft/ft_calloc.c \
			libft/ft_isalnum.c \
			libft/ft_isalpha.c \
			libft/ft_isascii.c \
			libft/ft_isdigit.c \
			libft/ft_isprint.c \
			libft/ft_memchr.c \
			libft/ft_memcmp.c \
			libft/ft_memcpy.c \
			libft/ft_memmove.c \
			libft/ft_memset.c \
			libft/ft_strchr.c \
			libft/ft_strdup.c \
			libft/ft_strlcat.c \
			libft/ft_strlcpy.c \
			libft/ft_strlen.c \
			libft/ft_strncmp.c \
			libft/ft_strnstr.c \
			libft/ft_strrchr.c \
			libft/ft_tolower.c \
			libft/ft_toupper.c \
			libft/ft_substr.c \
			libft/ft_strjoin.c \
			libft/ft_strtrim.c \
			libft/ft_split.c \
			libft/ft_itoa.c \
			libft/ft_strmapi.c \
			libft/ft_striteri.c \
			libft/ft_putchar_fd.c \
			libft/ft_putstr_fd.c \
			libft/ft_putendl_fd.c \
			libft/ft_putnbr_fd.c \
			libft/ft_lstnew.c \
			libft/ft_lstadd_front.c \
			libft/ft_lstsize.c \
			libft/ft_lstlast.c \
			libft/ft_lstadd_back.c \
			libft/ft_lstdelone.c \
			libft/ft_lstclear.c \
			libft/ft_lstiter.c \
			libft/ft_lstmap.c \

SRCS = ${addprefix ${SRC_PATH}, ${SRC_FILES}}

OBJ_PATH = ./objs/
OBJ_FILES = ${SRC_FILES:.c=.o}
OBJS = ${addprefix ${OBJ_PATH}, ${OBJ_FILES}}

DIR_DUP = @mkdir -p ${@D}

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

${OBJ_PATH}%.o:${SRC_PATH}%.c
	${DIR_DUP}
	@${CC} ${CFLAGS} -c $< -o $@

all: ${NAME}

${NAME}:	${OBJS}
	@ar rc ${NAME} ${OBJS}
	@echo "Compilation of libft done"

clean:
	@${RM} ${OBJ_PATH}

fclean:	clean
	@${RM} ${NAME}
	@echo "Clean libft done"

re:	fclean all

.PHONY: all clean fclean re
