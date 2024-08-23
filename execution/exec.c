/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 00:17:39 by zqouri            #+#    #+#             */
/*   Updated: 2024/08/22 21:40:22 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
    Builtins
    Executor "and or"
    pipes
    redirections
    Expanding

    first we serch for a pipe line
    then we search for redirections
    then we search for builtins
    then we search for commands 
*/

// void    ft_execut_builtin(t_cmd *cmd_list, t_env *env_list)
// {
//     //execute builtin
// }

// void    ft_execut_cmd(t_cmd *cmd_list, t_env *env_list)
// {
//     //execute command
// }

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
		{
			// if (cmd_list->in_redir)
			// 	ft_in_redir(cmd_list);
			// if (cmd_list->out_redir)
			// 	ft_out_redir(cmd_list);
			ft_execut(cmd_list, env_list);
		}
		wait(NULL);
	}
}

void    ft_execut_cmd(t_cmd *cmd_list, t_env *env_list)
{
	t_cmd	*tmp;
	int		pid;
	int		status;
	int		fd[2];
	int		saves[2];

	tmp = cmd_list;
	saves[0] = dup(STDIN_FILENO);
	saves[1] = dup(STDOUT_FILENO);
	if (serch_for_pipe(tmp))
	{
		while (tmp)
		{
			if (tmp->next == NULL)
			{
				process_child_end(tmp, env_list);
				break ;
			}
			pid = process_child_write(tmp, env_list, fd);
			tmp = tmp->next;
			if (tmp && tmp->next != NULL)
				pid = process_child_read(tmp, env_list, fd);
			else
				process_child_end(tmp, env_list);
			tmp = tmp->next;
		}
		waitpid(pid, &status, 0);
		while (waitpid(-1, NULL, 0) != -1)
			;
	}
	else if (is_builtin(tmp)){
		ft_builtin(tmp, env_list);}
	else
		ft_exec(tmp, env_list);
	dup2(saves[0], STDIN_FILENO);
	dup2(saves[1], STDOUT_FILENO);
}
