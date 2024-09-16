/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 23:15:58 by mohmazou          #+#    #+#             */
/*   Updated: 2024/09/16 20:55:40 by mohmazou         ###   ########.fr       */
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
// # define malloc(x) NULL

typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*prev;
	struct s_env	*next;
}	t_env;

typedef struct s_p_cmd
{
	int				pipe_line;
	char			*line;
	char			**cmd;
	char			**in_redir;
	char			**out_redir;
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
	int		*fd_tab;
	char	*f_name;
	int		status;
	int		len;
}	t_utils;

void	affich_array(char **array);

// free_all.c
/*
taking the size to allocate,
and takes a boolean to free the allocated memory 1 to free all, 0 to not free
*/
void	*ft_malloc(size_t size, int free);

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char *s1, char *set);
int		ft_isalnum(char c);
void	ft_strcpy(char *dst, char *src);
void	ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
int		all_space(char *line);
int		ft_check_syntax(char *line);
int		ft_check_direction(char *line);
int		ft_isspace(char c);
void	ft_env_list(t_env **env_list, char **env);
char	*ft_env_search(t_env *env_list, char *name);
void	ft_parsing(char *line, t_p_cmd **cp_list, t_env *env_list);
char	**ft_split_cmd(char *line, char c, int s_q, int d_q);
int		cnt_split(char *line, char c, int in_word);
int		is_expandable(char c);
char	*ft_get_name(char *str, int i);
int		c_ex(char *str);
int		not_expandable(char c);
int		ft_to_ex(char c);
int		new_len(char *line);
void	*allocat_zero(size_t size);
int		ft_cnt_red(char *line, char c);
void	join_exit(char *new_line, char *str, int *j, int *i);
void	get_line(char *line, t_p_cmd *cp_list, t_env *env_list);
char	*get_redir(char *line, int i);
void	in_qote(int *sq, int *dq, char c);
char	**get_in_rd(char *line, int dq, int sq);
char	**get_out_rd(char *line, int dq, int sq);
t_p_cmd	*ft_new_cp(char *cmd, int i, t_env *env_list);
void	cp_add_back(t_p_cmd **cp_list, t_p_cmd *new_cmd);
char	*expd_line(char *line, t_env *env);
void	ft_merge(t_cmd **cmd_list, t_p_cmd *cp_list, t_env *env_list);
t_cmd	*ft_new_cmd(t_p_cmd *cp_cmd, t_env *env_list);
void	cmd_add_back(t_cmd **cmd_list, t_cmd *new_cmd);
char	*rm_qot(char *str, int s_q, int d_q);
void	close_tab(int *fd_tab, int size);
int		open_in(char **in_redir, t_env *env);
int		open_out(char **out_redir, t_env *env);
char	*get_f_name(char *f_name, t_env *env);
char	*expd_rd(char *f_name, t_env *env);

#endif