/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 00:17:39 by zqouri            #+#    #+#             */
/*   Updated: 2024/10/29 08:58:23 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	fork1(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		ft_error("fork failed: ");
	return (pid);
}

void	pid_waiting(void)
{
	int	status;

	while (waitpid(-1, &status, 0) != -1)
	{
		if (WIFEXITED(status))
		{
			exit_status(WEXITSTATUS(status));
		}
		else if (WIFSIGNALED(status))
		{
			if (WTERMSIG(status) == 2)
			{
				write(1, "\n", 1);
				exit_status(130);
			}
			else if (WTERMSIG(status) == 3)
			{
				write(1, "Quit: 3\n", 8);
				exit_status(131);
			}
		}
	}
}

void	ft_execut_cmd(t_cmd *cmd, t_env **env_list, int fd_in, int fd_out)
{
	int		fd[2];

	fd_in = dup(STDIN_FILENO);
	fd_out = dup(STDOUT_FILENO);
	while (cmd)
	{
		if (cmd->next == NULL)
		{
			if (is_builtin(cmd) && cmd->pipe_line == 0)
				exit_status(ft_builtin(cmd, env_list));
			else
				process_child_end(cmd, env_list);
			break ;
		}
		process_child(cmd, env_list, fd);
		cmd = cmd->next;
	}
	dup2(fd_in, STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close_fd(fd_in, fd_out);
	pid_waiting();
}
