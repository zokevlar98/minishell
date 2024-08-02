/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 02:26:51 by zqouri            #+#    #+#             */
/*   Updated: 2024/08/02 16:26:37 by zqouri           ###   ########.fr       */
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
# define STD_OUT 1
# define STD_IN 0
//define tasks
# define EXEC 1

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
	// i need to add prev to make it double linked list
}    t_cmd;

// lib_utils
int     ft_strcmp(const char *s1, const char *s2);
int     ft_strncmp(char *s1, char *s2, size_t size);
char    *lower_case(char *str);
int     ft_check_env(t_cmd *cmd_list);
void    ft_putstr_fd(char *str, int fd);
void    ft_error(char *str);

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

//execution
void    ft_execut_cmd(t_cmd *cmd_list, t_env *env_list);
int     is_builtin(t_cmd *cmd_list);
#endif