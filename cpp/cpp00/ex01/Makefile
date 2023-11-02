NAME = PhoneBook

CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98
RM = /bin/rm -rf

YELLOW = \033[0;93m
MAGENTA = \033[0;95m

INCLUDE = Contact.hpp PhoneBook.hpp

SRC_FILES = Contact.cpp PhoneBook.cpp main.cpp

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
	@echo "${MAGENTA}Clear objects files"
	@(${RM} ${OBJ_DIR})

fclean: clean
	@echo "${MAGENTA}Clear executable files"
	@(${RM} ${NAME})

re: fclean all

.PHONY: all clean fclean re