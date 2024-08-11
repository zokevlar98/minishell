/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 04:45:05 by zqouri            #+#    #+#             */
/*   Updated: 2024/08/11 02:32:35 by zqouri           ###   ########.fr       */
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

// int ft_check_env(t_cmd *cmd_list)
// {
//     int     i;
//     char    *cmd;

//     i = 0;
//     cmd = cmd_list->cmd;
//     while (cmd[i] == '\t' || cmd[i] == ' ' || cmd[i] == '\n')
//         i++;
//     while (cmd[i])
//     {
//         if (cmd[i] == '$')
//             return (1);
//         i++;
//     }
//     return (0);
// }

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
}

void	ft_execut_pipe(t_cmd *cmd_list, t_env *env_list)
{
	int		fd[2];

	if (pipe(fd) == -1)
		ft_error("pipe failed\n");
	if (fork1() == 0)
	{
		close(fd[0]);
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			ft_error("dup2 failed\n");
		close(fd[1]);
		ft_execut(cmd_list, env_list);
	}
	if (fork1() == 0)
	{
		close(fd[1]);
		if (dup2(fd[0], STDIN_FILENO) == -1)
			ft_error("dup2 failed\n");
		close(fd[0]);
		ft_execut(cmd_list->next, env_list);
	}
	close(fd[0]);
	close(fd[1]);
	wait(NULL);
	wait(NULL);
}

void	process_child(t_cmd *cmd_list, t_env *env_list)
{
	int	fd[2];

	if (pipe(fd) == -1)
		ft_error("pipe failed\n");
	if (fork1() == 0)
	{
		close(fd[0]);
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			ft_error("dup2 failed\n");
		close(fd[1]);
		ft_execut(cmd_list, env_list);
	}
	else
	{
		close(fd[1]);
		if (dup2(fd[0], STDIN_FILENO) == -1)
			ft_error("dup2 failed\n");
		close(fd[0]);
	}
}

void	last_routine(t_cmd *cmd_list, t_env *env_list)
{
	if (fork1() == 0)
	{
		dup2(0, STDIN_FILENO);
		ft_execut(cmd_list, env_list);
	}
	wait(NULL);
}

void	 ft_execut_mul_pipe(t_cmd *cmd_list, t_env *env_list)
{
	t_cmd	*tmp;

	tmp = cmd_list;
	if (fork1() == 0)
	{
		while (tmp)
		{
			process_child(tmp, env_list);
			tmp = tmp->next;
		}
	}
	// last_routine(tmp, env_list);
	printf("nchoufo : %s\n", tmp->ful_cmd);
}

// void	ft_execut_redir(t_cmd *cmd_list, t_env *env_list)
// {
// // 4 case reduraction	
// }
