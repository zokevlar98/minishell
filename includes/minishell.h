/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 23:15:58 by mohmazou          #+#    #+#             */
/*   Updated: 2024/07/31 06:51:23 by mohmazou         ###   ########.fr       */
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

// environnement variables linked list
typedef struct s_env
{
    char	*name;
    char	*value;
    struct s_env	*next;
}	t_env;

// command linked list
typedef struct s_cmd
{
	char			*ful_cmd;
    int				pipe_line;
    char			*cmd;
    char			**args;
    char			**in_redir;
    char			**out_redir;
    struct s_cmd	*next;
}    t_cmd;

// lib_utils_1.c

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

// env_utils_1.c
void	ft_env_list(t_env **env_list,char **env);
char	*ft_env_search(t_env *env_list, char *name);

// parse.c
t_cmd	*ft_parse_line(char *line);
int		ft_check_line(char *line);

// tokenize.c
char	**tokenizing(char *line);
void	**tokenize_line(char *line, char ***tokens, int length,int *in_double_quote, int *in_single_quote, int *in_parentheses);


#endif