# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zqouri < zqouri@student.1337.ma >          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/30 23:02:35 by mohmazou          #+#    #+#              #
#    Updated: 2024/09/07 18:12:11 by zqouri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	minishell

HEADER			=	includes/minishell.h

CC				=	cc -Wall -Wextra -I ./includes 

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
					parsing/quoting.c \
					tokenization/tokenize.c \
					free_funcs/free_all.c \
					
OBJS		=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(OBJS) $(READLINE_FLAGS) -o $(NAME)

%.o:		%.c $(HEADER)
			$(CC) $(Flags) -c $< -o $@

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY: clean