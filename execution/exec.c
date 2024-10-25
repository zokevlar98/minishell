/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 00:17:39 by zqouri            #+#    #+#             */
/*   Updated: 2024/10/25 19:41:14 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    ft_execut_cmd(t_cmd *cmd, t_env **env_list, int fd_in, int fd_out)
{
	int		pid;
	int		status;
	int		fd[2];

	fd_in = dup(STDIN_FILENO); 
	fd_out = dup(STDOUT_FILENO); 
	while (cmd)
	{
		if (cmd->fd_in == -1 || cmd->fd_out == -1)
		{
			if (cmd->fd_in > 0)
				close(cmd->fd_in);
			if (cmd->fd_out > 1)
				close(cmd->fd_out);
			cmd = cmd->next;
			continue;
		}
		if (cmd->next == NULL)
		{
			if (is_builtin(cmd))
				ft_builtin(cmd, env_list);
			else
				process_child_end(cmd, env_list);
			break ;
		}
		pid = process_child_write(cmd, env_list, fd);
		cmd = cmd->next;
		if (cmd && cmd->next != NULL)
			pid = process_child_read(cmd, env_list, fd);
		else
		{
			if (is_builtin(cmd))
				ft_builtin(cmd, env_list);
			else
				process_child_end(cmd, env_list);
		}
		cmd = cmd->next;
	}
	dup2(fd_in, STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close_fd(fd_in, fd_out);
	while (waitpid(-1, &status, 0) != -1)
	{
		if (WIFEXITED(status))
			exit_status(WEXITSTATUS(status));
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
