/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri < zqouri@student.1337.ma >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:41:56 by zqouri            #+#    #+#             */
/*   Updated: 2024/08/13 18:41:56 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unset(t_cmd *cmd, t_env *env)
{
	t_env	*ptr;
	t_env	*tmp;
	t_env	*tmp1;

	ptr = env;
	if (!cmd->args[1])
		return ;
	while (ptr)
	{
		if (ft_strncmp(ptr->name, cmd->args[1], ft_strlen(ptr->name)))
		{
			tmp1 = ptr->next;
			tmp = ptr->prev;
			tmp->next = tmp1;
			tmp1->prev = tmp;
			return ;
		}
		ptr = ptr->next;
	}
}
