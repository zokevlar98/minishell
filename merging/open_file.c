
#include "minishell.h"

t_utils	*init_utils(void)
{
	t_utils	*utils;

	utils = ft_malloc(sizeof(t_utils), 0);
	utils->fd = 0;
	utils->i = 0;
	utils->fd_tab = NULL;
	utils->f_name = NULL;
	return (utils);
}

int	cp_arr(char **in_redir)
{
	int	i;

	i = 0;
	while (in_redir[i])
		i ++;
	return (i);
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

int	open_out(char **redir, t_env *env)
{
	t_utils	*u;

	u = init_utils();
	// u->fd_tab = ft_malloc(sizeof(int) * cp_arr(redir), 0);
	u->fd_tab = malloc(sizeof(int) * cp_arr(redir));
	if (!u->fd_tab)
		return (-1);
	while (redir && redir[u->i])
	{
		u->f_name = get_r_name(redir[u->i], env);
		u->f_name = get_f_name(u->f_name, env);
		if (redir[u->i][1] == '>')
			u->fd = open(u->f_name, O_WRONLY | O_CREAT | O_APPEND, 0644);
		else
			u->fd = open(u->f_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		u->fd_tab[u->i] = u->fd;
		u->i ++;
		if (u->fd == -1)
			break ;
	}
	close_tab(u->fd_tab, u->i - 1);
	return (u->fd);
}

int	open_in(char **redir, t_env *env)
{
	t_utils	*u;

	u = init_utils();
	// u->fd_tab = ft_malloc(sizeof(int) * cp_arr(redir), 0);
	u->fd_tab = malloc(sizeof(int) * cp_arr(redir));
	if (!u->fd_tab)
		return (-1);
	while (redir && redir[u->i])
	{
		u->f_name = get_r_name(redir[u->i], env);
		if (redir[u->i][1] == '<')
			printf("%s : heredoc> al5ra\n", rm_qot(u->f_name, 0, 0));
		else
		{
			u->f_name = get_f_name(u->f_name, env);
			if (!u->f_name)
				return (-1);
			u->fd = open(u->f_name, O_RDONLY);
			if (u->fd == -1)
				printf("minishell:%s: No such file or directory\n", u->f_name);
		}
		u->fd_tab[u->i] = u->fd;
		u->i ++;
		if (u->fd == -1)
			break ;
	}
	close_tab(u->fd_tab, u->i - 1);
	return (u->fd);
}
