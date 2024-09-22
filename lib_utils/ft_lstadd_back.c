/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 00:00:04 by zqouri            #+#    #+#             */
/*   Updated: 2024/09/21 03:27:07 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstadd_back(t_cmd **lst, t_cmd *new)
{
	t_cmd *last;
	
	if (!lst || !new)
		return ;
	if (*lst)
	{
		last = ft_lstlast(*lst);
		if (!last)
			return ;
		last->next = new;
	}
	else
		(*lst) = new;
}

t_env	*ft_lstlast_env(t_env *env)
{
	if (!env)
		return (NULL);
	while (env->next)
		env = env->next;
	return (env);
}
