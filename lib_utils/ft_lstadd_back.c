/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 00:00:04 by zqouri            #+#    #+#             */
/*   Updated: 2024/10/21 14:28:19 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
