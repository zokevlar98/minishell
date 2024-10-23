/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 04:45:05 by zqouri            #+#    #+#             */
/*   Updated: 2024/10/23 22:20:44 by mohmazou         ###   ########.fr       */
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

int is_builtin(t_cmd *cmd_list)
{
    char    *builtins[NUM_BUILTINS];
    int     i;
    char    *cmd;

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

void	ft_execut(t_cmd *cmd_list,t_env *env_list)
{
	char	**envp;
	char	*path;

	envp = ft_get_envp(env_list);
	if (!envp)
		printf("minishell: %s: No such file or directory\n", cmd_list->args[0]);//make with ft_putstr_fd
	path = find_path_env(cmd_list->args[0], envp);
	if (!path)
		ft_execution_error(cmd_list->args[0]);
	if (execve(path, cmd_list->args, envp) == -1)
		ft_execution_error(cmd_list->args[0]);
	exit(EXIT_SUCCESS);
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
		dup2(cmd_list->fd_in, STDIN_FILENO);// Redirects the standard input to the file descriptor fd_in
		close(fd[0]);
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			ft_error("dup2 failed\n");
		dup2(cmd_list->fd_out, STDOUT_FILENO);// Redirects the standard output to the file descriptor fd_out
		close(fd[1]);
		if (is_builtin(cmd_list))
		{
			ft_builtin(cmd_list, env_list);
			exit(EXIT_SUCCESS);
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
		dup2(cmd_list->fd_in, STDIN_FILENO);// Redirects the standard input to the file descriptor fd_in
		close(fd[0]);
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			ft_error("dup2 failed\n");
		dup2(cmd_list->fd_out, STDOUT_FILENO);// Redirects the standard output to the file descriptor fd_out
		close(fd[1]);
		if (is_builtin(cmd_list))
		{
			ft_builtin(cmd_list, env_list);
			exit(EXIT_SUCCESS);
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
	signal(SIGINT, SIG_IGN);
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		printf("fd in: %d\n", cmd_list->fd_in);
		dup2(cmd_list->fd_in, STDIN_FILENO);// Redirects the standard input to the file descriptor fd_in
		dup2(cmd_list->fd_out, STDOUT_FILENO);// Redirects the standard output to the file descriptor fd_out
		// if (cmd_list->fd_out != 1)
		// 	close(cmd_list->fd_out);
		// if (cmd_list->fd_in != 0)
		// 	close(cmd_list->fd_in);
		ft_execut(cmd_list, *env_list);
	}
	return (pid);
}
