/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 09:10:19 by zqouri            #+#    #+#             */
/*   Updated: 2024/10/22 23:00:14 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_env(t_cmd *cmd, t_env *env)
{
	t_env	*tmp;
	
	tmp = env;
	if (cmd && !cmd->args[1])
	{
		while (tmp)
		{
			if (tmp->value)
				printf("%s=%s\n", tmp->name, tmp->value);
			tmp = tmp->next;
		}
		return (0);
	}
	else
	{
		ft_putstr_fd("env: '", STDOUT_FILENO);
		ft_putstr_fd(cmd->args[1], STDOUT_FILENO);
		ft_putstr_fd("': No such file or directory\n", STDOUT_FILENO);
		return (127);
	}
}
