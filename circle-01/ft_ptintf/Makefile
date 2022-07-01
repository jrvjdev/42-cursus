# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaoribeiro <joaoribeiro@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/18 01:14:03 by joaoribeiro       #+#    #+#              #
#    Updated: 2021/12/18 01:14:06 by joaoribeiro      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= 		ft_call_str.c ft_call_int.c ft_call_lowx.c ft_call_p.c ft_call_percentage.c ft_call_u.c ft_call_upx.c		\
					ft_printf.c ft_call_char.c

OBJS		= 		$(SRCS:.c=.o)

CC			= 		gcc
CFLAGS		= 		-Wall -Wextra -Werror
LIB			= 		ar rcs
RM			= 		/bin/rm -f

NAME		= 		libftprintf.a

INCLUDE		= 		ft_printf.h

all			:		$(NAME)

$(NAME)		:		$(OBJS) $(INCLUDE)
					$(LIB) $(NAME) $(OBJS)

bonus		:		$(NAME)

.c.o		:
					$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $(<:.c=.o)

clean		:
					$(RM) $(OBJS) $(BONUS_OBJS)

fclean		:		clean
						$(RM) $(NAME)

re			:		fclean all

rebonus		:		fclean bonus

.PHONY		:		all clean fclean re bonus rebonus
