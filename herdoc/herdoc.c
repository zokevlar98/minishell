#include "../minishell.h"

int	to_herdoc(char *redir)
{
	if (redir[0] == '<' && redir[1] == '<')
		return (1);
	return (0);
}

char	*gnrt_name(void)
{
	char	*file_name;
	static int	i;

	file_name = ft_strjoin("herdoc", ft_itoa(i++));
	return (file_name);
}

int	del_quote(int *sq, int *dq, char r)
{
	if (r == '\'' && !(*dq))
	{
		*sq = !(*sq);
		return (1);
	}
	if (r == '"' && !(*sq))
	{
		*dq = !(*dq);
		return (1);
	}
	return (0);
}

char	*get_del(char *redir)
{
	int		i;
	int		j;
	char	*del;
	int		sq;
	int		dq;

	i = 2;
	j = 0;
	sq = 0;
	dq = 0;
	while (redir[i] && ft_isspace(redir[i]))
		i++;
	del = ft_malloc(ft_strlen(redir) - i + 1, 0);
	while (redir[i])
	{
		i += del_quote(&sq, &dq, redir[i]);
		if (!sq && !dq && redir[i] == '$' &&
			(redir[i + 1] == '\'' || redir[i + 1] == '"'))
			i++;
		i += del_quote(&sq, &dq, redir[i]);
		if (redir[i])
			del[j ++] = redir[i ++];
	}
	del[j] = '\0';
	return (del);
}

char	*get_buffer(int *s, char *red, int pipe_line, t_env *env)
{
	char	*line;
	char	*buffer;
	char	*del;
	int		fd_dup;
	int		expd;

	del = get_del(red);
	expd = will_expd(red);
	buffer = NULL;
	fd_dup = dup(STDIN_FILENO);
	while (1)
	{
		signal(SIGINT, ft_sig_herdoc);
		line = readline("> ");
		if (!line)
		{
			if (exit_status(-1) == -1337)
				*s = -1337;
			else
				*s = -42;
			rl_replace_line("", 0);
			break ;
		}
		if (ft_strcmp(line, del) == 0)
		{
			free(line);
			break ;
		}
		buffer = ft_strjoin(buffer, line);
		buffer = ft_strjoin(buffer, "\n");
		free(line);
	}
	dup2(fd_dup, STDIN_FILENO);
	close(fd_dup);
	if (expd)
		return (expended_buffer(buffer, env, pipe_line));
	return (buffer);
}

void	unlik_herdoc(char **redir)
{
	int	i;

	i = 0;
	while (redir[i])
			unlink(redir[i++]);
}

int	will_expd(char *del)
{
	while (*del)
	{
		if (*del == '\'' || *del == '\"')
			return (0);
		del ++;
	}
	return (1);
}

void	herdoc_hundeler(t_p_cmd **new_cmd,t_env *env, int *sig_flag)
{
	t_p_cmd	*cmd;
	int		i;
	int		fd;
	char	*file_name;
	char	**file_tab;
	char	*buffer;

	cmd = 	*new_cmd;
	file_tab = (char **)ft_malloc(sizeof(char *) * (cp_arr(cmd->redir) + 1), 0);
(void)env;
	i = 0;
	if (!cmd || !cmd->redir)
		return ;
	while (cmd->redir[i] && *sig_flag != -1337 && *sig_flag != -42)
	{
		if (to_herdoc(cmd->redir[i]))
		{
			file_name = gnrt_name();
			buffer = get_buffer(sig_flag, cmd->redir[i], cmd->pipe_line, env);
			fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
			file_tab[i] = file_name;
			write(fd, buffer, ft_strlen(buffer));
			close(fd);
			cmd->redir[i] = ft_strjoin("<<",file_name);
		}
		i ++;
	}
	file_tab[i] = NULL;
	if (*sig_flag == -1337 || *sig_flag == -42)
	{
		unlik_herdoc(file_tab);
		if (*sig_flag == -1337)
			exit_status(1);
		else
			exit_status(0);
	}
}