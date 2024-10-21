/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 04:16:56 by zqouri            #+#    #+#             */
/*   Updated: 2024/10/21 04:16:56 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define MAX_TOKENS 100
// # define malloc(x) NULL

# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>
# include <errno.h>
# include <dirent.h>
# include <limits.h>
# include <sys/wait.h>
# include <stddef.h>
# include <fcntl.h>


//define
# define NUM_BUILTINS 8
#define BLK "\e[1;90m"
#define RED "\e[1;91m"
#define GRN "\e[3;92m"
#define MAG "\e[1;95m"
#define CYN "\e[3;96m"
#define RST "\e[0m"

//global varaibles status

typedef struct s_global
{
	int	exit_status;
}	t_global;

extern t_global g_data;

// environnement variables linked list
typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}	t_env;

// command linked list
typedef struct s_p_cmd
{
	int				pipe_line;
	char			*line;
	char			**cmd;
	char			**redir;
	struct s_p_cmd	*next;
}	t_p_cmd;

typedef struct s_cmd
{
	int				pipe_line;
	char			**args;
	int				fd_in;
	int				fd_out;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_utils
{
	int		fd;
	int		i;
	int		j;
	int		k;
	char	*new_line;
	int		sq;
	int		dq;
	int		*fds_tab;
	char	*f_name;
	int		status;
	int		len;
}	t_utils;

// free_all.c
/*
taking the size to allocate,
and takes a boolean to free the allocated memory 1 to free all, 0 to not free
*/
void	*ft_malloc(size_t size, int free);


// lib_utils
int     ft_strcmp(const char *s1, const char *s2);
int     ft_strncmp(char *s1, char *s2, size_t size);
// char    *lower_case(char *str); i9dar nemsse7ha
void    ft_putstr_fd(char *str, int fd);
void    ft_error(char *str);
char	*ft_strchr(const char *s, int c);
char	**ft_split(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
void	ft_free(char **tab);
char	*ft_strtrim(char *s1, char *set);
int     ft_atoi(char *str);
char	*ft_itoa(int n);
int		size_array(char **array);
void    ft_execution_error(char *str);

// lib_utils_2
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_strcpy(char *dst, char *src);
void	ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
int		all_space(char *line);
int		ft_check_syntax(char *line);
int		ft_check_direction(char *line);
int		ft_isspace(char c);
int		is_caracter(char *str, char c);

// parsing_part

void	ft_parsing(char *line, t_p_cmd **cp_list, t_env *env_list);
char	**ft_split_cmd(char *line, char c, int s_q, int d_q);
int		cnt_split(char *line, char c, int in_word);
int		is_expandable(char c);
char	*ft_get_name(char *str, int i);
int		c_ex(char *str);
int		not_expandable(char c);
int		ft_to_ex(char c);
int		new_len(char *line, t_env *env);
void	*allocat_zero(size_t size);
int		ft_cnt_red(char *line, char c);
void	join_exit(char *new_line, int pipe_line, int *j, int *i);
void	get_line(char *line, t_p_cmd *cp_list, t_env *env_list);
char	*get_redir(char *line, int i);
void	in_qote(int *sq, int *dq, char c);
char	**get_rd(char *line, int dq, int sq);
t_p_cmd	*ft_new_cp(char *cmd, int i, t_env *env_list);
void	cp_add_back(t_p_cmd **cp_list, t_p_cmd *new_cmd);
char	*expd_line(char *line, t_env *env, int pipe_line);
void	ft_merge(t_cmd **cmd_list, t_p_cmd *cp_list, t_env *env_list);
t_cmd	*ft_new_cmd(t_p_cmd *cp_cmd, t_env *env_list);
void	cmd_add_back(t_cmd **cmd_list, t_cmd *new_cmd);
char	*rm_qot(char *str, int s_q, int d_q);
void	close_tab(int *fd_tab, int size, int in, int out);
void	open_red(t_p_cmd *cmd, int *fd_in, int *fd_out,t_env *env);
char	*get_f_name(char *f_name, t_env *env, int pipe_line);
char	*expd_rd(char *f_name, t_env *env, int pipe_line);
int		exit_status(int status);
void	ft_handle_signals(void);
int		ft_maxsize(t_env *env_list, int flag);
void	herdoc_hundeler(t_p_cmd **cmd,t_env *env, int *sig_flag);
void	ft_sig_herdoc(int sig);
int		to_expand(char *line);
int		cp_arr(char **in_redir);


// env_utils_1.c
char    **empty_env(void);
void	ft_change_env(t_env *env_list, char *name, char *value);
char	*ft_env_search(t_env *env_list, char *name);
t_env	*ft_env_new_(char *key, char *value);
t_env	*ft_env_new(char *env);
t_env	*ft_lstlast_env(t_env *env);
void	ft_env_add_back(t_env **env_list, t_env *new);
void	ft_env_list(t_env **env_list,char **env, int flag);
t_env	*find_env(t_env *env, char *name);
char	**ft_get_envp(t_env *env_list);
int		count_env(t_env *env);
char	**sort_env(t_env *env, int n);

//execution
void    ft_execut_cmd(t_cmd *cmd_list, t_env **env_list);
void	ft_execut(t_cmd *cmd_list, t_env *env_list);
char	*find_path_env(char *cmd, char *envp[]);
int		fork1(void);
int	    process_child_write(t_cmd *cmd_list, t_env **env_list, int fd[]);
int	    process_child_read(t_cmd *cmd_list, t_env **env_list, int fd[]);
int	    process_child_end(t_cmd *cmd_list, t_env **env_list);
char	*check_path(char **path_s, char *cmd);

//builtins
int     is_builtin(t_cmd *cmd_list);
void	ft_builtin(t_cmd *cmd_list, t_env **env_list);
void	ft_export_error(char *name);
void	print_list_declare(t_env **env);
char	*check_name_env(char *name);
int		check_empty_value(char *var);
void	ft_echo(t_cmd *cmd_list);
void	ft_cd(t_cmd *cmd_list, t_env *env_list);
void	ft_pwd(t_env *env);
void	ft_export(t_cmd *cmd, t_env **env);
void	ft_env(t_cmd *cmd, t_env *env);
void	ft_exit(t_cmd *cmd, int flag);
void	ft_unset(t_cmd *cmd, t_env **env);
void	shell_lvl(t_env *env);

//test
int		ft_lstsize(t_cmd *lst);
t_cmd	*ft_lstlast(t_cmd *lst);
void	ft_lstadd_back(t_cmd **lst, t_cmd *new);
void	affiche_env(t_env *env);
t_cmd	*ft_lstnew_cmd(char *cmd);
void	ft_lstadd_back_cmd(t_cmd **cmd_list, t_cmd *new);
void	ff(void);
void	close_fd(int *fd_tab, int size);

#endif