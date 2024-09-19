
#include "minishell.h"

int		serch_for_pipe(t_cmd *cmd_list)
{
	while (cmd_list != NULL)
	{
		if (cmd_list->pipe_line >= 1)
			return (1);
		cmd_list = cmd_list->next;
	}
	return (0);
}

void	ft_exec(t_cmd *cmd_list, t_env *env_list)
{
	if (ft_lstsize(cmd_list) == 1)
	{
		if (fork1() == 0)
			ft_execut(cmd_list, env_list);
		wait(NULL);
	}
}

void    ft_execut_cmd(t_cmd *cmd_list, t_env **env_list)
{
	t_cmd	*tmp;
	int		pid;
	int		status;
	int		fd[2];
	int		saves[2];

	tmp = cmd_list;
	saves[0] = dup(STDIN_FILENO);
	saves[1] = dup(STDOUT_FILENO);
	while (tmp)
	{
		if (tmp->fd_in == -1 || tmp->fd_out == -1)
			return ;
		if (tmp->next == NULL)
		{
			if (is_builtin(tmp))
				ft_builtin(tmp, env_list);
			else
				process_child_end(tmp, env_list);
			break ;
		}
		pid = process_child_write(tmp, env_list, fd);
		tmp = tmp->next;
		if (tmp && tmp->next != NULL)
			pid = process_child_read(tmp, env_list, fd);
		else
		{
			if (is_builtin(tmp))
				ft_builtin(tmp, env_list);
			else
				process_child_end(tmp, env_list);
		}
		tmp = tmp->next;
	}
	dup2(saves[0], STDIN_FILENO);
	dup2(saves[1], STDOUT_FILENO);
	while (waitpid(-1, &status, 0) != -1)
		;
}
