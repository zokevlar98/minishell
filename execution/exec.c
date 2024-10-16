/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 00:17:39 by zqouri            #+#    #+#             */
/*   Updated: 2024/10/16 16:45:53 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_execut_cmd(t_cmd *cmd_list, t_env **env_list)
{
	t_cmd	*tmp;
	int		pid;
	int		status;
	int		saves[2];
	int		fd[2];

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
	close_tab(saves, 2);
	while (waitpid(-1, &status, 0) != -1)
		;
}
