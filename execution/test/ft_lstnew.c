/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 23:46:53 by zqouri            #+#    #+#             */
/*   Updated: 2024/08/07 23:50:30 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*ft_lstnew(void)
{
	t_cmd *new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->ful_cmd = NULL;
	new->pipe_line = 0;
	new->cmd = NULL;
	new->args = NULL;
	new->fd_in = 0;
	new->fd_out = 1;
	new->next = NULL;
	return (new);
}
