# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/30 23:02:35 by mohmazou          #+#    #+#              #
#    Updated: 2024/08/10 00:50:30 by zqouri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	minishell

HEADER			=	includes/minishell.h

CC				=	cc

Flags			=	-Wall -Wextra -Werror -I ./includes

READLINE_FLAGS	=	-lreadline \

SRCS			=	main.c \
					\
					lib_utils/ft_error.c 				\
					lib_utils/ft_putstr_fd.c			\
					lib_utils/ft_split_exec.c			\
					lib_utils/ft_strjoin.c				\
					lib_utils/lib_utilis_1.c 			\
					lib_utils/lib_utilis_2.c 			\
					lib_utils/lib_utilis_exec.c 		\
					lib_utils/ft_split_up.c 			\
					execution/exec_utils_1.c			\
					execution/exec_utils_2.c			\
					execution/exec.c					\
					env_var/env_utils_1.c				\
					execution/test/ft_lstnew.c			\
					execution/test/ft_lstlast.c			\
					execution/test/ft_lstadd_back.c		\
					execution/test/ft_init.c			\
					execution/test/ft_lstsize.c			\
					builtins/builtin_cmd.c				\
					builtins/builtin_utils.c			\

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