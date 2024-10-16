
#include "minishell.h"

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

void	open_red(t_p_cmd *cmd, int *fd_in, int *fd_out,t_env *env)
{
	t_utils	*u;
	char **redir;
	
	redir = cmd->redir;
	u = init_utils(redir);
	while (redir && redir[u->i])
	{
		u->f_name = get_r_name(redir[u->i], env);
		u->f_name = get_f_name(u->f_name, env, cmd->pipe_line);
		if (!u->f_name)
		{
			*fd_in = -1;
			*fd_out = -1;
			break ;
		}
		if (redir[u->i][0] == '>')
		{
			if (redir[u->i][1] == '>')
				u->fd = open(u->f_name, O_WRONLY | O_CREAT | O_APPEND, 0644);
			else
				u->fd = open(u->f_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
			*fd_out = u->fd;
			u->fds_tab[u->i] = u->fd;
			if (u->fd == -1)
				break ;
		}
		if (redir[u->i][0] == '<')
		{
			u->fd = open(u->f_name, O_RDONLY);
			if (redir[u->i][1] == '<')
			{
				unlink(u->f_name);
			}
			*fd_in = u->fd;
			u->fds_tab[u->i] = u->fd;
			if (u->fd == -1)
			{
				printf("minishell:%s: No such file or directory\n", u->f_name);
				break ;
			}
		}
		u->i ++;
	}
	close_tab(u->fds_tab, u->i, *fd_in, *fd_out);
	while (redir && redir[u->i])
	{
		if (redir[u->i][0] == '<' && redir[u->i][1] == '<')
		{
			u->f_name = get_r_name(redir[u->i], env);
			u->f_name = get_f_name(u->f_name, env, cmd->pipe_line);
			unlink(u->f_name);
		}
		u->i ++;
	}
}