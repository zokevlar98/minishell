/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 06:24:21 by mohmazou          #+#    #+#             */
/*   Updated: 2024/08/28 06:37:13 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_cmd	*create_cmd(t_p_cmd *cmd_p)
{
	t_cmd	*new_cmd;

	new_cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new_cmd)
		return (NULL);
	new_cmd->pipe_line = cmd_p->pipe_line;
	new_cmd->args = cmd_p->cmd;
	new_cmd->fd_in = 0;
	new_cmd->fd_out = 1;
	new_cmd->next = NULL;
	return (new_cmd);
}

void	ft_add_cmd(t_cmd **cmd_list, t_cmd *new_cmd)
{
	t_cmd	*tmp;

	if (!*cmd_list)
	{
		*cmd_list = new_cmd;
		return ;
	}
	tmp = *cmd_list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_cmd;
}

t_cmd	*ft_p_cmd_to_cmd(t_p_cmd *cmd_p_list)
{
	t_cmd	*cmd_list;
	t_cmd	*new_cmd;

	cmd_list = NULL;
	while (cmd_p_list)
	{
		new_cmd = create_cmd(cmd_p_list);
		// if (!new_cmd)
		// {
		// 	ft_free_cmd_list(cmd_list);
		// 	return (NULL);
		// }
		ft_add_cmd(&cmd_list, new_cmd);
		cmd_p_list = cmd_p_list->next;
	}
	return (cmd_list);
}
