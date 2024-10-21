/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:44:35 by zqouri            #+#    #+#             */
/*   Updated: 2024/10/20 22:53:17 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	echo_option(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	if (str[i] != '-')
		return (1);
	if (str[++i] != 'n')
		return (1);
	while (str[i])
	{
		if (str[i] != 'n')
			return (1);
		i++;
	}
	return (0);
}

void	ft_echo(t_cmd *cmd)
{
	int		i;
	int		n_flag;

	n_flag = 0;
	i = 1;
	while (cmd->args[i] && !echo_option(cmd->args[i]))
	{
		n_flag++;
		i++;
	}
	while (cmd->args[i] && cmd->args[i + 1])
	{
		ft_putstr_fd(cmd->args[i], cmd->fd_out);
		ft_putstr_fd(" ", cmd->fd_out);
		i++;
	}
	if (cmd->args[i])
		ft_putstr_fd(cmd->args[i], cmd->fd_out);
	if (!n_flag)
		ft_putstr_fd("\n", cmd->fd_out);
}
