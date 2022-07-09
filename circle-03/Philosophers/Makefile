# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: V <V@student.42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 19:54:21 by joaribei          #+#    #+#              #
#    Updated: 2022/07/09 17:47:25 by V                ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRC = $(wildcard philo/*.c)
OBJ = $(SRS:%.c=%.o)
FLG = -Wall -Werror -Wextra
INC = -lpthread
RM = rm -f

all:
	@echo "start compile"
	gcc -g $(SRC) $(INC)

clean:
	$(RM) $(NAME)

re: clean all
