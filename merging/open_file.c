/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 06:39:48 by mohmazou          #+#    #+#             */
/*   Updated: 2024/10/27 15:38:41 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	cp_arr(char **in_redir)
{
	int	i;

	i = 0;
	while (in_redir[i])
		i ++;
	return (i);
}

t_utils	*init_utils(char **redir)
{
	t_utils	*utils;

	utils = ft_malloc(sizeof(t_utils), 0);
	utils->fd = 0;
	utils->i = 0;
	utils->fds_tab = ft_malloc(sizeof(int) * cp_arr(redir), 0);
	utils->f_name = NULL;
	utils->flag = 1;
	return (utils);
}

char	*get_r_name(char *redir, t_env *env)
{
	int		i;

	(void)env;
	i = 0;
	if (redir[i] == '<' || redir[i] == '>')
		i++;
	if (redir[i] == '<' || redir[i] == '>')
		i++;
	while (redir[i] == ' ')
		i++;
	return (redir + i);
}

int	err_get_name(char *f_name, int *fd_in, int *fd_out)
{
	if (!f_name)
	{
		*fd_in = -1;
		*fd_out = -1;
		exit_status(1);
		return (-1);
	}
	return (1);
}

void	open_out(t_utils **u, char *red, int *fd_out)
{
	
	if (red[1] == '>')
		(*u)->fd = open((*u)->f_name, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		(*u)->fd = open((*u)->f_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	*fd_out = (*u)->fd;
	(*u)->fds_tab[(*u)->i] = (*u)->fd;
	if ((*u)->fd == -1)
	{
		ft_putstr_fd("minishell: Permission denied\n", STDERR_FILENO);
		exit_status(1);
	}
}

void	open_in(t_utils **u, char *redir, int *fd_in)
{
	(*u)->fd = open((*u)->f_name, O_RDONLY);
	if (redir[1] == '<')
	{
		unlink((*u)->f_name);
	}
	*fd_in = (*u)->fd;
	(*u)->fds_tab[(*u)->i] = (*u)->fd;
	if ((*u)->fd == -1)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd((*u)->f_name, STDERR_FILENO);
		ft_putstr_fd(": No such file or directory:\n", STDERR_FILENO);
		exit_status(1);
	}
}

void	unlinker(char **redir, int i,t_env *env)
{
	char	*f_name;

	while (redir && redir[i])
	{
		if (redir[i][0] == '<' && redir[i][1] == '<')
		{
			f_name = get_r_name(redir[i], env);
			f_name = get_f_name(f_name, env, 1);
			unlink(f_name);
		}
		i ++;
	}
}

void	open_red(t_p_cmd *cmd, int *fd_in, int *fd_out, t_env *env)
{
	t_utils	*u;
	char	**redir;

	redir = cmd->redir;
	u = init_utils(redir);
	while (redir && redir[u->i] && u->fd != -1)
	{
		u->f_name = get_r_name(redir[u->i], env);
		u->f_name = get_f_name(u->f_name, env, cmd->pipe_line);
		u->fd = err_get_name(u->f_name, fd_in, fd_out);
		if (redir[u->i][0] == '>' && u->fd != -1)
			open_out(&u, redir[u->i], fd_out);
		if (redir[u->i][0] == '<' && u->fd != -1)
			open_in(&u, redir[u->i], fd_in);
		u->i ++;
	}
	close_tab(u->fds_tab, u->i, *fd_in, *fd_out);
	unlinker(redir, u->i, env);
}
