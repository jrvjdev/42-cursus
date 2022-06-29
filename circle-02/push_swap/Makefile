# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 20:08:59 by joaribei          #+#    #+#              #
#    Updated: 2022/06/12 11:11:49 by joaribei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

# Color variables
GRN = \033[0;32m
GRNGRN = \033[38;5;46m
RED = \033[0;31m
RST = \033[0m

# Variables for path s of source, header
INC_DIR = ./includes
SHARED_DIR = ./shared
CHECKER_DIR = ./checker
PUSH_SWAP_DIR = ./push_swap

CHECKER_SRCS =		${CHECKER_DIR}/checker.c

SHARED_SRCS =		${SHARED_DIR}/ft_atoi.c \
					${SHARED_DIR}/lst_add_back.c \
					${SHARED_DIR}/lst_clear.c \
					${SHARED_DIR}/lst_delone.c \
					${SHARED_DIR}/lst_last.c \
					${SHARED_DIR}/lst_new.c \
					${SHARED_DIR}/lst_size.c \
					${SHARED_DIR}/lst_sorted.c \
					${SHARED_DIR}/lts_add_front.c \
					${SHARED_DIR}/print_list.c \
					${SHARED_DIR}/push.c \
					${SHARED_DIR}/reverse.c \
					${SHARED_DIR}/rotate.c \
					${SHARED_DIR}/swap.c \

PUSH_SWAP_SRCS :=	${PUSH_SWAP_DIR}/chunk.c \
					${PUSH_SWAP_DIR}/cost_to_move.c \
					${PUSH_SWAP_DIR}/error.c \
					${PUSH_SWAP_DIR}/push_swap.c \
					${PUSH_SWAP_DIR}/sort1.c \
					${PUSH_SWAP_DIR}/sort2.c \
					${PUSH_SWAP_DIR}/sort3.c \
					${PUSH_SWAP_DIR}/utils.c \

# Variables for path of object files and binary targets
BUILD_DIR = ./build
OBJ_DIR = ${BUILD_DIR}/obj
BIN_DIR = ${BUILD_DIR}/bin
BIN = ${BIN_DIR}/${NAME}
PUSH_SWAP_OBJS = $(subst .c,.o,$(subst ${PUSH_SWAP_DIR},${OBJ_DIR},${PUSH_SWAP_SRCS}))
CHECKER_OBJS = $(subst .c,.o,$(subst ${CHECKER_DIR},${OBJ_DIR},${CHECKER_SRCS}))
SHARED_OBJS = $(subst .c,.o,$(subst ${SHARED_DIR},${OBJ_DIR},${SHARED_SRCS}))

# Variables for compiler configs
CC = gcc
CFLAGS = -Werror -Wall -Wextra
INCLUDES = -I$(INC_DIR)

all: ${NAME}

checker: ${CHECKER_SRC} 
	${CC} ${CFLAGS} ${INCLUDES} ${CHECKER_OBJ} -o ${BIN_DIR}/checker

$(NAME): ${BUILD_DIR} | ${PUSH_SWAP_OBJS} ${SHARED_OBJS}
	$(CC) $(CFLAGS) $(PUSH_SWAP_OBJS) ${SHARED_OBJS} -o $(BIN)

${OBJ_DIR}/%.o: ${PUSH_SWAP_DIR}/%.c
	$(CC) $(CFLAGS) -I${INC_DIR} -c $< -o $@
	@echo "$(GRNGRN)/$(RST)\c"

${OBJ_DIR}/%.o: ${SHARED_DIR}/%.c
	$(CC) $(CFLAGS) -I${INC_DIR} -c $< -o $@
	@echo "$(GRNGRN)/$(RST)\c"

${BUILD_DIR}:
	@mkdir -p ${BUILD_DIR}
	@mkdir -p ${BIN_DIR}
	@mkdir -p ${OBJ_DIR}

clean:
	@rm -rf $(OBJ_DIR)
	@printf "\e[31mclean done\e[0m\n"

fclean:
	@rm -rf $(BUILD_DIR)
	@printf "$(RED)fclean done\e[0m\n"

re:		fclean all

.PHONY: all exe clean fclean re