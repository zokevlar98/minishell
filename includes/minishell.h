/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:03:36 by mohmazou          #+#    #+#             */
/*   Updated: 2024/07/29 02:11:47 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

# include <unistd.h>
# include <stdlib.h>
# include <libc.h>

typedef struct s_cmd
{
	char			*ful_cmd;
    int				pipe_line;
    char			*cmd;
    char			**args;
    char			*in_redir;
    char			*out_redir;
    struct s_cmd	*next;
}    t_cmd;

typedef struct s_env
{
    char	*name;
    char	*value;
    struct s_env	*next;
}	t_env;

// libtf functions
int		ft_strlen(char *str);
char	*ft_strdup(char *str);
int		ft_strcmp(const char *s1, const char *s2);
char	**ft_split(char *line, char c);

char	**ft_split(char *str, char c);
char	*ft_get_word(char *str, char c);
int		ft_count_words(char *str, char c);

// minishell functions
void	ft_error(char *str);


// minishell_utils functions
void	ft_minishell(char *line, t_env *env_par, t_cmd **cmd);
int		checking_line(char *line);

// env_utils functions
void	ft_envlst(char **env, t_env **env_lst);
char	*ft_env_befor(char *str);
char	*ft_env_after(char *str);
void	ft_add_last(t_env **env_lst, t_env *new);
t_env	*lst_new(char *str);
char	*get_env_value(t_env *env_lst, char *name);

// cmd_utils functions
void free_cmdlst(t_cmd *cmd);
void	ft_cdmlst(t_cmd **cmd,char **cmd_lines);




#endif