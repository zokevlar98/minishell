/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 02:26:51 by zqouri            #+#    #+#             */
/*   Updated: 2024/07/31 05:08:16 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <errno.h>
# include <dirent.h>
# include <limits.h>
# include <sys/wait.h>
# include <stddef.h>

//define
# define NUM_BUILTINS 8

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
    int				pipe_line;//indice of command 0 -> ....
    char			*cmd;
    char			**args;
    char			**in_redir;
    char			**out_redir;
    struct s_cmd	*next;
}    t_cmd;

// lib_utils_1.c

int ft_strcmp(const char *s1, const char *s2);

// env_utils_1.c
void    ft_env_list(t_env **env_list,char **env);

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


int     ft_strcmp(const char *s1, const char *s2);

// env_utils_1.c
void     ft_env_list(t_env **env_list,char **env);


void    ft_execut_cmd(t_cmd *cmd_list, t_env *env_list);

#endif