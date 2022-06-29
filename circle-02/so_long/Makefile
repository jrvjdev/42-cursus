# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/29 16:45:21 by joaribei          #+#    #+#              #
#    Updated: 2022/06/29 16:45:22 by joaribei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

# Color variables
GRN = \033[0;32m
GRNGRN = \033[38;5;46m
RED = \033[0;31m
RST = \033[0m

# Variables for path s of source, header
LIB_DIR = ./libs
INC_DIR = ./headers
SRC_DIR = ./src

SRCS := ${SRC_DIR}/animation.c ${SRC_DIR}/collider.c \
		${SRC_DIR}/color.c \
		${SRC_DIR}/enemy.c ${SRC_DIR}/error.c \
		${SRC_DIR}/exit.c ${SRC_DIR}/fence.c \
		${SRC_DIR}/get_next_line.c ${SRC_DIR}/hook.c \
		${SRC_DIR}/init_all.c ${SRC_DIR}/key.c \
		${SRC_DIR}/line.c ${SRC_DIR}/maloc.c \
		${SRC_DIR}/map.c ${SRC_DIR}/object.c \
		${SRC_DIR}/player.c ${SRC_DIR}/pokeball.c \
		${SRC_DIR}/pole.c ${SRC_DIR}/program.c \
		${SRC_DIR}/rando_int.c ${SRC_DIR}/background.c \
		${SRC_DIR}/so_long.c ${SRC_DIR}/sprite.c \
		${SRC_DIR}/string.c ${SRC_DIR}/menu.c \
		${SRC_DIR}/transform.c ${SRC_DIR}/vector2.c \
		${SRC_DIR}/window.c

LIBS := ${LIB_DIR}/libmlx.a

# Variables for path of object files and binary targets
BUILD_DIR = ./build
OBJ_DIR = ${BUILD_DIR}/obj
BIN_DIR = ${BUILD_DIR}/bin
BIN = ${BIN_DIR}/${NAME}
OBJS = $(subst .c,.o,$(subst ${SRC_DIR},${OBJ_DIR},${SRCS}))

# Variables for compiler configs
CC = gcc
CFLAGS = -Werror -Wall -Wextra
INCLUDES = -I$(INC_DIR)
LINKS =  -framework OpenGL -framework AppKit

.PHONY: all exe clean fclean re

all : $(NAME)

$(NAME) : ${OBJS} | ${BIN_DIR}
	@make -C minilibx
	@mkdir -p $(LIB_DIR)
	@cp -r minilibx/libmlx.a ${LIB_DIR}/libmlx.a
	@$(CC) ${CFLAGS} $(INCLUDES) $(LINKS) $(LIBS) -o $(BIN) $^
	@cp -r xpm $(BIN_DIR)/xpm
	@printf "\n$(GRNGRN)$@ built🗣\e[0m\n"

${OBJ_DIR}/%.o : ${SRC_DIR}/%.c | ${OBJ_DIR} 
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo "$(GRNGRN)/$(RST)\c"

${BIN_DIR}:
	@mkdir -p $(BIN_DIR)

${OBJ_DIR} :
	@mkdir -p ${OBJ_DIR}

exe:
	@echo "     - Executing $(NAME)... \n"
	@./$(BIN) $(BIN_DIR)/xpm/map.ber
	@echo "\n     - Done -"

clean :
	@make clean -C minilibx
	@rm -r $(OBJ_DIR)
	@rm -r $(LIBS)
	@printf "\e[31mclean done\e[0m\n"

fclean :
	@make clean -C minilibx
	@rm -r $(BUILD_DIR)
	@rm -r $(LIBS)
	@printf "$(RED)fclean done\e[0m\n"

re : fclean all
