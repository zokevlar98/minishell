/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:44:35 by zqouri            #+#    #+#             */
/*   Updated: 2024/09/17 01:46:39 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(t_cmd *cmd)
{
	int		i;// test : echo -nnnn -nnn h

	i = 1;
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
