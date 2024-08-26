/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri < zqouri@student.1337.ma >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:38:07 by zqouri            #+#    #+#             */
/*   Updated: 2024/08/13 15:38:07 by zqouri           ###   ########.fr       */
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
# include <fcntl.h>


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
	struct s_env	*prev;
    struct s_env	*next;
}	t_env;

// command linked list
// typedef struct command
// {
// 	char **cmd;
// 	int in;
// 	int out;
// 	t_env *env;
// 	struct command *next;
// };
typedef struct s_cmd
{
	char			*ful_cmd;// it must be a double pointer
    int				pipe_line;//indice of command 0 -> ....
    char			*cmd;
    char			**args;
    int             fd_in;
    int             fd_out;
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
char	*ft_strchr(const char *s, int c);
char	**ft_split(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
void	ft_free(char **tab);
char	**ft_split_up(char *s);
char	*ft_strtrim(char *s1, char *set);
int     ft_atoi(char *str);
char	*ft_itoa(int n);

// lib_utils_2
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		is_caracter(char *str, char c);

// env_utils_1.c
void	ft_env_list(t_env **env_list,char **env);
char	*ft_env_search(t_env *env_list, char *name);

// parse.c
t_cmd	*ft_parse_line(char *line);
int		ft_check_line(char *line);


int     ft_strcmp(const char *s1, const char *s2);

// env_utils_1.c
void	ft_change_env(t_env *env_list, char *name, char *value);
char	*ft_env_search(t_env *env_list, char *name);
t_env	*ft_env_new(char *env);
void	ft_env_add_back(t_env **env_list, t_env *new);
void     ft_env_list(t_env **env_list,char **env);
void	ft_add_env_back(t_env **env, t_env *new);

//execution
void    ft_execut_cmd(t_cmd *cmd_list, t_env **env_list);
int     is_builtin(t_cmd *cmd_list);
void	ft_execut(t_cmd *cmd_list, t_env *env_list);
char	**ft_get_envp(t_env *env_list);
char	*find_path_env(char *cmd, char *envp[]);
int		fork1(void);
int	    process_child_write(t_cmd *cmd_list, t_env **env_list, int fd[]);
int	    process_child_read(t_cmd *cmd_list, t_env **env_list, int fd[]);
int	    process_child_end(t_cmd *cmd_list, t_env **env_list);

//builtins
void	ft_builtin(t_cmd *cmd_list, t_env **env_list);
void	ft_echo(t_cmd *cmd_list);
void	ft_cd(t_cmd *cmd_list, t_env *env_list);
void	ft_pwd(t_env *env);
void	ft_export(t_cmd *cmd, t_env *env);
void	ft_env(t_cmd *cmd, t_env *env);
void	ft_exit(t_cmd *cmd);
void	ft_unset(t_cmd *cmd, t_env **env);
void	shell_lvl(t_env *env);

//test
t_cmd	*ft_lstnew(void);
int		ft_lstsize(t_cmd *lst);
t_cmd	*ft_lstlast(t_cmd *lst);
void	ft_lstadd_back(t_cmd **lst, t_cmd *new);
void	ft_init(t_cmd *cmd_list);
void    ft_init_pars(t_cmd **cmd_list, char *line);
void	affiche_node(t_cmd *cmd_list);
void	affiche_env(t_env *env);
void	print_args(char **args);
t_cmd	*ft_lstnew_cmd(char *cmd);
void	ft_lstadd_back_cmd(t_cmd **cmd_list, t_cmd *new);
t_env	*ft_env_new_(char *key, char *value);

#endif