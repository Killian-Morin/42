NAME = megaphone

RM = rm -rf
CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98

BLUE = \033[0;34m
RED = \033[0;31m
WHITE = \033[0;97m

SRC_FILES = megaphone.cpp

OBJ_DIR = ./objs/
OBJ_FILES = ${addprefix ${OBJ_DIR}, ${SRC_FILES:.cpp=.o}}

DIR_DUP = @mkdir -p ${@D}

all: ${NAME}

${NAME}: ${OBJ_FILES}
	@(${CC} ${FLAGS} ${OBJ_FILES} -o ${NAME})
	@echo "${BLUE}Compiled executable${WHITE}"

${OBJ_DIR}%.o: %.cpp
	@${DIR_DUP}
	@${CC} ${FLAGS} -c $< -o $@

clean:
	@(${RM} ${OBJ_DIR})
	@echo "${RED}Clean objects files${WHITE}"

fclean: clean
	@(${RM} ${NAME})
	@echo "${RED}Clean executable file${WHITE}"

re: fclean all

.PHONY: all clean fclean re