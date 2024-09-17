
NAME			=	minishell

HEADER			=	includes/minishell.h


CC				=	cc -Wall -Wextra -Werror -I ./includes -fsanitize=address -g

READLINE_FLAGS	=	-lreadline \


SRCS			=	main.c								\
					lib_utils/ft_error.c 				\
					lib_utils/ft_putstr_fd.c			\
					lib_utils/ft_split_exec.c			\
					lib_utils/ft_strjoin.c				\
					lib_utils/lib_utilis_1.c 			\
					lib_utils/lib_utilis_2.c 			\
					lib_utils/lib_utilis_3.c 			\
					lib_utils/lib_utilis_exec.c 		\
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
					env_var/env_utils_2.c				\
					execution/test/outils_test.c		\
					builtins/builtin_cmd.c				\
					builtins/builtin_utils.c			\
					builtins/ft_echo.c					\
					builtins/ft_cd.c					\
					builtins/ft_pwd.c					\
					builtins/ft_env.c					\
					builtins/ft_export.c				\
					builtins/ft_exit.c					\
					builtins/ft_unset.c					\
					Parsing/check_syntax.c				\
					Parsing/check_syntax_red.c 			\
					Parsing/parsing.c 					\
					Parsing/expanding_utils_1.c 		\
					Parsing/expanding_utils_2.c 		\
					Parsing/cp_list_utils.c 			\
					Parsing/get_line.c					\
					Parsing/get_line_utils.c 			\
					Parsing/expanding.c 				\
					merging/merge.c 					\
					merging/merge_utils.c				\
					merging/open_file.c					\
					merging/expaind_red.c 				\
					free_funcs/free_all.c 				\
					



OBJS		=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(OBJS) $(READLINE_FLAGS) -o $(NAME)

%.o:		%.c $(HEADER)
			$(CC) -c $< -o $@

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY: clean