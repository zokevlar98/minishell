# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/30 23:02:35 by mohmazou          #+#    #+#              #
#    Updated: 2024/08/30 14:51:39 by mohmazou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	minishell

HEADER			=	includes/minishell.h

CC				=	cc

Flags			=	-Wall -Wextra -Werror -I ./includes

READLINE_FLAGS	=	-lreadline \

SRCS			=	main.c \
					lib_utils/lib_utilis_1.c \
					lib_utils/lib_utilis_2.c \
					env_var/env_utils_1.c \
					parsing/parse.c \
					parsing/cmd_p_list.c \
					parsing/cmd_list.c \
					parsing/check_syntax.c \
					Parsing/check_syntax_red.c \
					parsing/add_space.c \
					Parsing/expanding2.c \
					Parsing/open_file.c \
					tokenization/tokenize.c \
					free_funcs/free_all.c \
					


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

.PHONY: clean