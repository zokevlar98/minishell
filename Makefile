# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/30 23:02:35 by mohmazou          #+#    #+#              #
#    Updated: 2024/07/30 23:24:40 by mohmazou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	minishell

HEADER			=	includes/minishell.h

CC				=	cc

Flags			=	-Wall -Wextra -Werror

READLINE_FLAGS	=	-lreadline \

SRCS			=	srcs/main.c \
					\
					lib_utils/lib_utilis_1.c \
					
					


OBJS			=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(Flags) $(READLINE_FLAGS) $(OBJS) -o $(NAME)

%.o:		%.c $(HEADER)
			$(CC) $(Flags) -c $< -o $@

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all