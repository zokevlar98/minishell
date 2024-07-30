/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 23:15:58 by mohmazou          #+#    #+#             */
/*   Updated: 2024/07/31 00:02:25 by mohmazou         ###   ########.fr       */
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
    char			*in_redir;
    char			*out_redir;
    struct s_cmd	*next;
}    t_cmd;

// lib_utils_1.c
int ft_strcmp(const char *s1, const char *s2);

// env_utils_1.c
ft_env_list(t_env **env_list,char **env);

#endif