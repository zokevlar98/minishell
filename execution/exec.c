/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 00:17:39 by zqouri            #+#    #+#             */
/*   Updated: 2024/08/10 01:47:31 by zqouri           ###   ########.fr       */
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
	else
		printf("9ewada ft_exec\n");
}

void    ft_execut_cmd(t_cmd *cmd_list, t_env *env_list)
{
	t_cmd	*tmp;

	tmp = cmd_list;
	// while (tmp)
	// {
		if (serch_for_pipe(tmp))
			ft_execut_mul_pipe(tmp, env_list);
		else if (is_builtin(tmp))
			ft_builtin(tmp);
		else
			ft_exec(tmp, env_list);
		// tmp = tmp->next;
	// }
}
