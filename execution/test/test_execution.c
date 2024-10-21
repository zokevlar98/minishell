/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 22:49:42 by zqouri            #+#    #+#             */
/*   Updated: 2024/10/22 00:42:34 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execut_command(t_cmd *cmd,t_env *env)
{
	int	fd[2];
	int	pid;
	
	if (cmd->next && pipe(fd) == -1)
		ft_putstr_fd("error: Broken pipe\n", 2);
	pid = fork1();
	if (pid == 0)
	{
	}
}

void	ft_execut_builtin(t_cmd *cmd_list, t_env **env_list)
{
	char	*cmd;
	
	cmd = cmd_list->args[0];
	if (!cmd || cmd_list->fd_in == -1 || cmd_list->fd_out == -1)
		return ;
	dup2(cmd_list->fd_in , STDIN_FILENO);
	dup2(cmd_list->fd_out , STDOUT_FILENO);
	if (ft_strncmp(cmd, "echo", ft_strlen("echo")) == 0)
		g_data.exit_status = ft_echo(cmd_list);
	else if (ft_strncmp(cmd, "cd", ft_strlen("cd")) == 0)
		g_data.exit_status = ft_cd(cmd_list, *env_list);
	else if (ft_strncmp(cmd, "pwd", ft_strlen("pwd")) == 0)
		g_data.exit_status = ft_pwd(*env_list);
	else if (ft_strncmp(cmd, "env", ft_strlen("env")) == 0)
		g_data.exit_status = ft_env(cmd_list, *env_list);
	else if (ft_strncmp(cmd, "export", ft_strlen("export")) == 0)
		g_data.exit_status = ft_export(cmd_list, env_list);
	else if (ft_strncmp(cmd, "exit", ft_strlen("exit")) == 0)
		g_data.exit_status = ft_exit(cmd_list, 1);
	else if (ft_strncmp(cmd, "unset", ft_strlen("unset")) == 0)
		g_data.exit_status = ft_unset(cmd_list, env_list);
}

int	execution_builtin(t_cmd *cmd, t_env **env)
{
    if (cmd->args && !cmd->next && is_builtin(cmd))// i can also check out_redir if 1 or 2
	{
		ft_execut_builtin(cmd, env);
		return (1);
	}
	return (0);
}

void	ft_test_execution(t_cmd *cmd, t_env **env, int in_save, int out_save)
{
    int pid;
    int status;

    if (execution_builtin(cmd, env))//I will check if i have one builtins first the i check multiple command
		return ;
	in_save = dup(STDIN_FILENO);
	out_save - dup(STDOUT_FILENO);
	while (cmd)
	{
		pid = execut_command(cmd, env);
		cmd = cmd->next;
	}
}
