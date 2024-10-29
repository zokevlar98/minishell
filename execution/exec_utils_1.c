/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 04:45:05 by zqouri            #+#    #+#             */
/*   Updated: 2024/10/29 06:33:24 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_builtin(t_cmd *cmd_list)
{
	char	*builtins[NUM_BUILTINS];
	int		i;
	char	*cmd;

	i = 0;
	cmd = cmd_list->args[0];
	builtins[0] = "echo";
	builtins[1] = "cd";
	builtins[2] = "pwd";
	builtins[3] = "export";
	builtins[4] = "unset";
	builtins[5] = "env";
	builtins[6] = "exit";
	builtins[7] = NULL;
	while (builtins[i])
	{
		if (ft_strcmp(builtins[i], cmd) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	ft_execut(t_cmd *cmd_list, t_env *env_list)
{
	char	**envp;
	char	*path;

	envp = ft_get_envp(env_list);
	if (!envp)
	{
		ft_putstr_fd("minishell: \n", STDERR_FILENO);
		ft_putstr_fd(cmd_list->args[0], STDERR_FILENO);
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
	}
	path = find_path_env(cmd_list->args[0], envp);
	if (!path)
		ft_execution_error(cmd_list->args[0]);
	if (cmd_list->fd_in != -1 && cmd_list->fd_out != -1)
	{
		if (execve(path, cmd_list->args, envp) == -1)
			ft_execution_error(cmd_list->args[0]);
		else
			exit_status(1);
	}
	exit(exit_status(-1));
}

int	process_child_write(t_cmd *cmd_list, t_env **env_list, int fd[])
{
	int	pid;

	pipe(fd);
	signal(SIGINT, SIG_IGN);
	pid = fork1();
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		dup2(cmd_list->fd_in, STDIN_FILENO);
		close(fd[0]);
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			ft_error("dup2 failed");
		dup2(cmd_list->fd_out, STDOUT_FILENO);
		close(fd[1]);
		if (is_builtin(cmd_list))
		{
			exit(ft_builtin(cmd_list, env_list));
		}
		else 
			ft_execut(cmd_list, *env_list);
	}
	else
	{
		close(fd[1]);
		if (dup2(fd[0], STDIN_FILENO) == -1)
			ft_error("dup2 failed");
		close(fd[0]);
	}
	ft_cloe_file(cmd_list->fd_out);
	return (pid);
}

int	process_child_read(t_cmd *cmd_list, t_env **env_list, int fd[])
{
	int	pid;

	pipe(fd);
	signal(SIGINT, SIG_IGN);
	pid = fork1();
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		dup2(cmd_list->fd_in, STDIN_FILENO);
		close(fd[0]);
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			ft_error("dup2 failed\n");
		dup2(cmd_list->fd_out, STDOUT_FILENO);
		close(fd[1]);
		if (is_builtin(cmd_list))
		{
			exit(ft_builtin(cmd_list, env_list));
		}
		else
			ft_execut(cmd_list, *env_list);
	}
	else
	{
		close(fd[1]);
		if (dup2(fd[0], STDIN_FILENO) == -1)
			ft_error("dup2 failed\n");
		close(fd[0]);
	}
	ft_cloe_file(cmd_list->fd_out);
	return (pid);
}

int	process_child_end(t_cmd *cmd_list, t_env **env_list)
{
	int	pid;

	pid = fork1();
	signal(SIGINT, SIG_IGN);
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		dup2(cmd_list->fd_in, STDIN_FILENO);
		dup2(cmd_list->fd_out, STDOUT_FILENO);
		if (is_builtin(cmd_list))
			exit(ft_builtin(cmd_list, env_list));
		else
			ft_execut(cmd_list, *env_list);
	}
	close_fd(cmd_list->fd_in, cmd_list->fd_out);
	return (pid);
}
