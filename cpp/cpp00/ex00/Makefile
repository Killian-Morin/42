NAME = megaphone

RM = rm -rf
CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98

YELLOW = \033[0;93m
MAGENTA = \033[0;95m

SRC_FILES = megaphone.cpp

OBJ_DIR = ./objs/
OBJ_FILES = ${addprefix ${OBJ_DIR}, ${SRC_FILES:.cpp=.o}}

DIR_DUP = @mkdir -p ${@D}

all: ${NAME}
	@echo "${YELLOW}Compiled executable"

${NAME}: ${OBJ_FILES}
	@(${CC} ${FLAGS} ${OBJ_FILES} -o ${NAME})

${OBJ_DIR}%.o: %.cpp
	@${DIR_DUP}
	@${CC} ${FLAGS} -c $< -o $@

clean:
	@echo "${MAGENTA}Clean objects files"
	@(${RM} ${OBJ_DIR})

fclean: clean
	@echo "${MAGENTA}Clean executable file"
	@(${RM} ${NAME})

re: fclean all

.PHONY: all clean fclean re