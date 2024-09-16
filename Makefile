# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/02 04:06:29 by mohmazou          #+#    #+#              #
#    Updated: 2024/09/16 20:56:56 by mohmazou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			=	minishell

HEADER			=	includes/minishell.h

CC				=	cc -Wall -Wextra -Werror -I ./includes 
CC				=	cc

Flags			=	-Wall -Wextra -Werror  -g -fsanitize=address

READLINE_FLAGS	=	-lreadline \

SRCS			=	main.c \
					free_funcs/free_all.c \
					lib_utils/lib_utilis_1.c \
					lib_utils/lib_utilis_2.c \
					lib_utils/lib_utilis_3.c \
					env_var/env_utils_1.c \
					Parsing/check_syntax.c \
					Parsing/check_syntax_red.c \
					Parsing/expanding.c \
					Parsing/open_file.c \
					parsing/quoting.c \
					tokenization/tokenize.c \
					free_funcs/free_all.c \
					Parsing/parsing.c \
					Parsing/expanding_utils_1.c \
					Parsing/expanding_utils_2.c \
					Parsing/cp_list_utils.c \
					Parsing/get_line.c \
					Parsing/get_line_utils.c \
					Parsing/expanding.c \
					merging/merge.c \
					merging/merge_utils.c \
					merging/open_file.c \
					merging/expaind_red.c \

OBJS			=	$(SRCS:.c=.o)

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
