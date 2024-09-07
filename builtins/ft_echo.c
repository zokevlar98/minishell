/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri < zqouri@student.1337.ma >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:44:35 by zqouri            #+#    #+#             */
/*   Updated: 2024/09/07 20:46:46 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(t_cmd *cmd)
{
	int		i;

	i = 1;
	while (cmd->args[i] != NULL)
	{
		if (ft_strncmp(cmd->args[i], "-n", ft_strlen(cmd->args[i])) == 0)
			i++;
		ft_putstr_fd(cmd->args[i], cmd->fd_out);
		if (cmd->args[i + 1] != NULL)
			ft_putstr_fd(" ", cmd->fd_out);
		i++;
	}
	if (ft_strncmp(cmd->args[1], "-n", ft_strlen(cmd->args[1])) == 0)//some conflie with read line
		return (1);
	ft_putstr_fd("\n", cmd->fd_out);
	return (0);
}
