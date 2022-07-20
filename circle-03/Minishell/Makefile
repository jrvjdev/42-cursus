# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: V <V@student.42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 20:08:59 by joaribei          #+#    #+#              #
#    Updated: 2022/07/12 19:03:34 by V                ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#name fo the project
NAME = minishell

# Color variables
GRN = \033[0;32m
GRNGRN = \033[38;5;46m
RED = \033[0;31m
RST = \033[0m

# Variables for path s of source, header
INC_DIR 	=	./includes
SRC_DIR 	=	./sources

CHAR		=	${SRC_DIR}/char
COMMAND		=	${SRC_DIR}/command
ENV			=	${SRC_DIR}/env
LIST		=	${SRC_DIR}/list
MEMORY		=	${SRC_DIR}/memory
PARSE		=	${SRC_DIR}/parse
SIGNAL		=	${SRC_DIR}/signal
STRING		=	${SRC_DIR}/string

SRCS		=	${CHAR}/is_alpha.c \
				${CHAR}/is_lowercase.c \
				${CHAR}/is_uppercase.c \
				${CHAR}/is_whitespace.c \
				${CHAR}/reference.c \
				${CHAR}/to_lower.c \
				${CHAR}/to_upper.c \
				${COMMAND}/cd.c \
				${COMMAND}/check.c \
				${COMMAND}/create.c \
				${COMMAND}/delete.c \
				${COMMAND}/execute.c \
				${COMMAND}/reference.c \
				${ENV}/create.c \
				${ENV}/get.c \
				${ENV}/reference.c \
				${LIST}/add.c \
				${LIST}/reference.c \
				${LIST}/remove.c \
				${LIST}/size.c \
				${MEMORY}/calloc.c \
				${MEMORY}/copy.c \
				${MEMORY}/free.c \
				${MEMORY}/malloc.c \
				${MEMORY}/realloc.c \
				${MEMORY}/reference.c \
				${MEMORY}/set.c \
				${PARSE}/dquote.c \
				${PARSE}/parse.c \
				${PARSE}/util_array.c \
				${PARSE}/util_debuging.c \
				${PARSE}/util_parse.c \
				${PARSE}/util_str.c \
				${SIGNAL}/reference.c \
				${STRING}/copy.c \
				${STRING}/dup.c \
				${STRING}/equals.c \
				${STRING}/is_quote.c \
				${STRING}/itoa.c \
				${STRING}/length.c \
				${STRING}/reference.c \
				${STRING}/split.c \
				${SRC_DIR}/minishell.c \

# Variables for path of object files and binary targets
BUILD_DIR	= 	./build
OBJ_DIR		= 	${BUILD_DIR}/obj
BIN_DIR		= 	${BUILD_DIR}/bin
BIN			= 	${BIN_DIR}/${NAME}
OBJS		= 	$(subst .c,.o,$(subst ${SRC_DIR},${OBJ_DIR},${SRCS}))

# Variables for compiler configs
CC			=	gcc
CFLAGS		=	-Werror -Wall -Wextra
INCLUDES	=	-I$(INC_DIR)

all: ${BUILD_DIR} ${NAME}

$(NAME): ${OBJS}
	@$(CC) $(CFLAGS) -lreadline $^ -o $(BIN)

exe: ${OBJS}
	@$(CC) $(CFLAGS) -lreadline $^ -o $(NAME)

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	@mkdir -p ${dir $@}
	$(CC) $(CFLAGS) -I${INC_DIR} -c $< -o  $@
	@echo "$(GRNGRN)/$(RST)\c"

${BUILD_DIR}:
	@mkdir -p ${BUILD_DIR}
	@mkdir -p ${BIN_DIR}
	@mkdir -p ${OBJ_DIR}

run: all
	@echo "Running ${NAME}"
	@./${BIN}

clean:
	@rm -rf $(OBJ_DIR)
	@printf "\e[31mclean done\e[0m\n"

fclean:
	@rm -rf $(BUILD_DIR)
	@printf "$(RED)fclean done\e[0m\n"

re:		fclean all

.PHONY: all run clean fclean re
