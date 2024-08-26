/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 04:45:05 by zqouri            #+#    #+#             */
/*   Updated: 2024/08/26 00:39:43 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fork1(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		ft_error("fork failed\n");
	return (pid);
}

int is_builtin(t_cmd *cmd_list)
{
    char    *builtins[NUM_BUILTINS];
    int     i;
    char    *cmd;

    i = 0;
    cmd = lower_case(cmd_list->cmd);
    
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
        if (ft_strncmp(builtins[i], cmd, ft_strlen(builtins[i])) == 0)
            return (1);
        i++;
    }
    return (0);
}

void	ft_execut(t_cmd *cmd_list,t_env *env_list)
{
	char	**envp;
	char	*path;
	char	**cmd;

	envp = ft_get_envp(env_list);
	if (!envp)
		ft_error("malloc failed\n");
	path = find_path_env(cmd_list->cmd, envp);
	if (!path)
		ft_error("command not found\n");
	cmd = ft_split_up(cmd_list->ful_cmd);
	if (execve(path, cmd, envp) == -1)
		ft_error("execve failed\n");
	exit(1);
}

int	process_child_write(t_cmd *cmd_list, t_env **env_list, int fd[])
{
	int	pid;

	pipe(fd);
	pid = fork1();
	if (pid == 0)
	{
		dup2(cmd_list->fd_in, STDIN_FILENO);// Redirects the standard input to the file descriptor fd_in
		close(fd[0]);
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			ft_error("dup2 failed\n");
		dup2(cmd_list->fd_out, STDOUT_FILENO);// Redirects the standard output to the file descriptor fd_out
		close(fd[1]);
		if (is_builtin(cmd_list))
		{
			ft_builtin(cmd_list, env_list);
			exit(0);
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
	return (pid);
}

int	process_child_read(t_cmd *cmd_list, t_env **env_list, int fd[])
{
	int	pid;

	pipe(fd);
	pid = fork1();
	if (pid == 0)
	{
		dup2(cmd_list->fd_in, STDIN_FILENO);// Redirects the standard input to the file descriptor fd_in
		close(fd[0]);
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			ft_error("dup2 failed\n");
		dup2(cmd_list->fd_out, STDOUT_FILENO);// Redirects the standard output to the file descriptor fd_out
		close(fd[1]);
		if (is_builtin(cmd_list))
		{
			ft_builtin(cmd_list, env_list);
			exit(0);
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
	return (pid);
}

int	process_child_end(t_cmd *cmd_list, t_env **env_list)
{
	int	pid;

	pid = fork1();
	if (pid == 0)
	{
		dup2(cmd_list->fd_in, STDIN_FILENO);// Redirects the standard input to the file descriptor fd_in
		dup2(cmd_list->fd_out, STDOUT_FILENO);// Redirects the standard output to the file descriptor fd_out
		ft_execut(cmd_list, *env_list);
	}
	return (pid);
}
