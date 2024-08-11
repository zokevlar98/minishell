/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 09:10:19 by zqouri            #+#    #+#             */
/*   Updated: 2024/08/11 09:22:47 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_cmd *cmd, t_env *env)
{
	t_env	*tmp;
	
	tmp = env;
	if (!cmd->args[1])
	{
		while (tmp)
		{
			printf("%s=%s\n", tmp->name, tmp->value);
			tmp = tmp->next;
		}
	}
	else
		ft_error("env: no options or arguments");
}
