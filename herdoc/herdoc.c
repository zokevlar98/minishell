#include "minishell.h"

// int	herdoc_hundeler1(char *del, t_env *env)
// {
// 	int		fd;
// 	char	*line;
// 	char	*new_path;
// 	char	*buffer;
// 	static int	i;
// (void)env;
// 	buffer = NULL;
// 	new_path = ft_strjoin("/tmp/mohmazou/herdoc", ft_itoa(i++));
// 	while (1)
// 	{
// 		line = readline("> ");
// 		if (!line)
// 			break ;
// 		if (ft_strcmp(line, del) == 0)
// 		{
// 			free(line);
// 			break ;
// 		}
// 		buffer = ft_strjoin(buffer, line);
// 		buffer = ft_strjoin(buffer, "\n");
// 		free(line);
// 	}
// 	fd = open(new_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	if (fd == -1)
// 		ft_error("open failed");
// 	write(fd, buffer, ft_strlen(buffer));
// 	close(fd);
// 	fd = open(new_path, O_RDONLY);
// 	if (fd == -1)
// 		ft_error("open failed");
// 	return (fd);
// }

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

char	*get_del(char *redir)
{
	int		i;
	char	*del;

	i = 2;
	while (redir[i] == ' ')
		i++;
	del = ft_strdup(redir + i);
	return (del);
}

char	*get_buffer(int *s,char *del)
{
	char	*line;
	char	*buffer;
	int fd_dup;
	buffer = NULL;
	fd_dup = dup(0);
	while (1)
	{
		signal(SIGINT, ft_sig_herdoc);
		line = readline("> ");
		if (!line)
			break ;
		if (ft_strcmp(line, del) == 0)
		{
			free(line);
			break ;
		}
		buffer = ft_strjoin(buffer, line);
		buffer = ft_strjoin(buffer, "\n");
		free(line);
	}
	dup2(fd_dup, 0);
	if (exit_status(-1) == -1337)
	{
		*s = -1337;
		exit_status(1);
	}
	return (buffer);
}

void	herdoc_hundeler(t_p_cmd **new_cmd,t_env *env, int *sig_flag)
{
	t_p_cmd	*cmd;
	int		i;
	int		fd;
	char	*del;
	char	*file_name;
	char	*buffer;
	cmd = *new_cmd;
(void)env;
	i = 0;
	if (!cmd || !cmd->redir)
		return ;
	while (cmd->redir[i] && *sig_flag != -1337)
	{
		if (to_herdoc(cmd->redir[i]))
		{
			del = get_del(cmd->redir[i]);
			file_name = gnrt_name();
			fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
			buffer = get_buffer( sig_flag,del);
			write(fd, buffer, ft_strlen(buffer));
			close(fd);
			cmd->redir[i] = ft_strjoin("<<",file_name);
		}
		i ++;
	}
	
	
}