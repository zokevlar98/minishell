
NAME			=	minishell

HEADER			=	includes/minishell.h gb/garbage.h

CC				=	cc -Wall -Wextra -Werror

READLINE_FLAGS	=	-lreadline \

USER = $(shell echo $$USER)

# LDFLAGS = -L/goinfre/$(USER)/homebrew/opt/readline/lib
# CPPFLAGS = -I/goinfre/$(USER)/homebrew/opt/readline/include

# LDFLAGS = -L/Users/$(USER)/.brew/opt/readline/lib
# CPPFLAGS = -I/Users/$(USER)/.brew/opt/readline/include

SRCS			=	main.c								\
					lib_utils/ft_error.c 				\
					lib_utils/ft_putstr_fd.c			\
					lib_utils/ft_split_exec.c			\
					lib_utils/ft_strjoin.c				\
					lib_utils/lib_utilis_1.c 			\
					lib_utils/lib_utilis_2.c 			\
					lib_utils/lib_utilis_3.c 			\
					lib_utils/lib_utilis_4.c 			\
					lib_utils/lib_utilis_5.c	 		\
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
					env_var/env_utils_3.c				\
					env_var/env_utils_4.c				\
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
					gb/gb.c								\
					signals/signals.c					\
					herdoc/herdoc.c						\
					herdoc/herdoc_expd.c				\
					merging/open_file_utils.c			\
					herdoc/herdoc_utils.c				\

					
RED             =   \033[0;31m
GREEN           =   \033[0;32m
RESET           =   \033[0m

OBJS		=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			@echo "$(GREEN)Loading$(RESET)"
			@$(CC) $(OBJS) $(READLINE_FLAGS) -o $(NAME) $(CPPFLAGS) $(LDFLAGS)
			@sleep 1
			@echo "$(GREEN)Minishell Ready$(RESET)"

%.o:		%.c $(HEADER)
			@$(CC) -c $< -o $@

clean:
			@echo "$(RED)Cleaning$(RESET)"
			@rm -rf $(OBJS)

fclean:		clean
			@rm -rf $(NAME)

re:			fclean all

.PHONY: clean