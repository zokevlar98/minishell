NAME			=	minishell

HEADER			=	includes/minishell.h

LIBFT			=	libft/libft.a

CC				=	cc

Flags			=	-Wall -Wextra -Werror -I ./includes

READLINE_FLAGS	=	-lreadline \

SRCS			=	srcs/minishell.c \
					srcs/minishell_utils.c \
					srcs/env_utils_1.c \
					srcs/env_utils_2.c \
					srcs/cmd_utils.c \
					libft/lib_utils1.c \
					libft/ft_split.c \
					


OBJS			=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)  #$(LIBFT)
			$(CC) $(Flags) $(READLINE_FLAGS) $(OBJS) -o $(NAME) #$(LIBFT)

%.o:		%.c $(HEADER)
			$(CC) $(Flags) -c $< -o $@

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY: clean