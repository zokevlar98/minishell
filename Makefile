# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/30 23:02:35 by mohmazou          #+#    #+#              #
#    Updated: 2024/08/02 21:00:47 by zqouri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	minishell

HEADER			=	includes/minishell.h

CC				=	cc

Flags			=	-Wall -Wextra -Werror -I ./includes

READLINE_FLAGS	=	-lreadline \

SRCS			=	main.c \
					\
					lib_utils/lib_utilis_1.c 		\
					lib_utils/lib_utilis_exec.c 	\
					lib_utils/ft_error.c 			\
					lib_utils/ft_putstr_fd.c		\
					lib_utils/ft_split_exec.c		\
					lib_utils/ft_strjoin.c			\
					execution/exec.c				\
					execution/exec_utils_1.c		\
					execution/exec_utils_2.c		\
					env_var/env_utils_1.c			\
					execution/exec_utils_1.c		\
					# builtins/builtin_cmd.c			\

OBJS		=	$(SRCS:.c=.o)

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