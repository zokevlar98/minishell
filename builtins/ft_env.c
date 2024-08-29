/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri < zqouri@student.1337.ma >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 09:10:19 by zqouri            #+#    #+#             */
/*   Updated: 2024/08/29 08:59:23 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_cmd *cmd, t_env *env)
{
	t_env	*tmp;
	
	tmp = env;
	if (cmd && !cmd->args[1])
	{
		while (tmp)
		{
			if (tmp->value && tmp->name)
				printf("%s=%s\n", tmp->name, tmp->value);
			else
				printf("%s=\n", tmp->name);
			tmp = tmp->next;
		}
	}
	else
	{
		ft_putstr_fd("env: '", 1);
		ft_putstr_fd(cmd->args[1], 1);
		ft_putstr_fd("': No such file or directory\n", 1);
	}
}
