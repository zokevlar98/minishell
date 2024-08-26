# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/30 23:02:35 by mohmazou          #+#    #+#              #
#
#    Updated: 2024/08/26 01:48:32 by zqouri           ###   ########.fr        #
#
#    Updated: 2024/07/31 01:39:08 by mohmazou         ###   ########.fr        #
#
#                                                                              #
# **************************************************************************** #

NAME			=	minishell

HEADER			=	includes/minishell.h

CC				=	cc -Wall -Wextra -Werror -g -fsanitize=address -I ./includes 

READLINE_FLAGS	=	-lreadline \


SRCS			=	main.c 								\
					lib_utils/ft_error.c 				\
					lib_utils/ft_putstr_fd.c			\
					lib_utils/ft_split_exec.c			\
					lib_utils/ft_strjoin.c				\
					lib_utils/lib_utilis_1.c 			\
					lib_utils/lib_utilis_2.c 			\
					lib_utils/lib_utilis_exec.c 		\
					lib_utils/ft_split_up.c 			\
					lib_utils/ft_atoi.c 				\
					lib_utils/ft_itoa.c 				\
					lib_utils/ft_lstnew.c				\
					lib_utils/ft_lstlast.c				\
					lib_utils/ft_lstadd_back.c			\
					lib_utils/ft_lstsize.c				\
					execution/exec_utils_1.c			\
					execution/exec_utils_2.c			\
					execution/exec.c					\
					env_var/env_utils_1.c				\
					execution/test/outils_test.c		\
					execution/test/ft_init.c			\
					builtins/builtin_cmd.c				\
					builtins/builtin_utils.c			\
					builtins/ft_echo.c					\
					builtins/ft_cd.c					\
					builtins/ft_pwd.c					\
					builtins/ft_env.c					\
					builtins/ft_export.c				\
					builtins/ft_exit.c					\
					builtins/ft_unset.c					\



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