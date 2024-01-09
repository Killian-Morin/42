NAME = BSP

CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98
RM = /bin/rm -rf

BLUE = \033[0;34m
RED = \033[0;31m
WHITE = \033[0;97m

SRC_FILES = main.cpp \
			Fixed.cpp \
			Point.cpp \
			bsp.cpp

OBJ_DIR = ./objs/
OBJ_FILES = ${addprefix ${OBJ_DIR}, ${SRC_FILES:.cpp=.o}}

DIR_DUP = @mkdir -p ${@D}

all: ${NAME}

${OBJ_DIR}%.o: %.cpp
	@${DIR_DUP}
	@${CC} ${FLAGS} -c $< -o $@

${NAME}: ${OBJ_FILES}
	@${CC} ${FLAGS} ${OBJ_FILES} -o ${NAME}
	@echo "${BLUE}Compiled executable${WHITE}"

clean:
	@(${RM} ${OBJ_DIR})
	@echo "${RED}Clean objects files${WHITE}"

fclean: clean
	@(${RM} ${NAME})
	@echo "${RED}Clean executable files${WHITE}"

re: fclean all

run: all
	./${NAME}

show: FLAGS += -D SHOWMSG=1
show: re run

unshow: FLAGS += -D SHOWMSG=0
unshow: re run

.PHONY: all clean fclean re run show unshow