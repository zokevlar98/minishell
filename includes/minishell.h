/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 23:15:58 by mohmazou          #+#    #+#             */
/*   Updated: 2024/08/10 08:36:21 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <readline/history.h>

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <libc.h>

# define MAX_TOKENS 100

// allocation struct
typedef struct s_alloc
{
	void			*ptr;
	struct s_alloc	*next;
}	t_alloc;

// environnement variables linked list
typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}	t_env;

// command linked list
typedef struct s_cmd
{
	// char			*ful_cmd;
	int				pipe_line;
	// char			*cmd;
	char			**cmd;
	char			**in_redir;
	char			**out_redir;
	struct s_cmd	*next;
}	t_cmd;

// free_all.c
/*
taking the size to allocate,
and takes a boolean to free the allocated memory 1 to free all, 0 to not free
*/
void	*ft_malloc(size_t size, int free);

// lib_utils_1.c

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

// lib_utils_2.c
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char *s1, char *set);
// env_utils_1.c
void	ft_env_list(t_env **env_list, char **env);
char	*ft_env_search(t_env *env_list, char *name);

// parse.c
t_cmd	*ft_parse_line(char *line, t_env *env_list);

// cmd_list.c
void	ft_fill_cmd_list(t_cmd **cmd_list, char **all_tokens, int pipe);
void	affich_cmd_list(t_cmd *cmd_list);

// check_syntax_red.c
int		ft_check_direction(char *line);

// check_syntax.c
int		ft_check_syntax(char *line);
int		ft_check_quote(char *line);
void	in_quotes(char line_i, int *single_quote, int *double_quote);

// add_space.c
char	*ft_add_space(char *line);

// tokenize.c
char	**tokenizing(char *line);
void	**tokenize_line(char *line, char ***tokens, int length, int *in_double_quote, int *in_single_quote, int *in_parentheses);
int		ft_check_tokens(char **tokens);

//expanding.c
char	**expand_tokens(char **tokens, t_env *env_list);

#endif