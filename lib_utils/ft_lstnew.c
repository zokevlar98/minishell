/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri < zqouri@student.1337.ma >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 23:46:53 by zqouri            #+#    #+#             */
/*   Updated: 2024/08/29 09:00:33 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*ft_lstnew_cmd(char *cmd)
{
	t_cmd	*new;
	char	**args;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	// new->ful_cmd = ft_strdup(cmd);
	args = ft_split(cmd, ' ');
	// new->cmd = ft_strdup(args[0]);
	new->args = args;
	new->fd_in = 0;
	new->fd_out = 1;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back_cmd(t_cmd **cmd_list, t_cmd *new)
{
	t_cmd	*last;

	if (!cmd_list || !new)
		return ;
	if (*cmd_list)
	{
		last = ft_lstlast(*cmd_list);
		if (!last)
			return ;
		last->next = new;
	}
	else
		(*cmd_list) = new;
}
