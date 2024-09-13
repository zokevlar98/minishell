/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:44:35 by zqouri            #+#    #+#             */
/*   Updated: 2024/09/13 23:24:16 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(t_cmd *cmd)
{
	int		i;

	i = 1;
	//i can use ft_strtrim to remove the quotes and single quotes
	//i can also use ft_strchr
	if (cmd->args[i] && ft_strncmp(cmd->args[i], "-n", ft_strlen(cmd->args[i])) == 0)
	{
		while (cmd->args[++i] != NULL)
		{
			ft_putstr_fd(cmd->args[i], cmd->fd_out);
			if (cmd->args[i + 1] != NULL)
				ft_putstr_fd(" ", cmd->fd_out);
		}
	}
	else
	{
		while (cmd->args[i] != NULL)
		{
			ft_putstr_fd(cmd->args[i], cmd->fd_out);
			if (cmd->args[i + 1] != NULL)
				ft_putstr_fd(" ", cmd->fd_out);
			i++;
		}
		ft_putstr_fd("\n", cmd->fd_out);
	}
}
