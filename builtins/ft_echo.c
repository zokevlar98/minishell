/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:44:35 by zqouri            #+#    #+#             */
/*   Updated: 2024/10/25 01:57:20 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

int	ft_echo(t_cmd *cmd)
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

	while (cmd->args[i])
	{
		printf("%s", cmd->args[i ++]);
		if (cmd->args[i])
			printf(" ");
	}
	if (!n_flag)
		printf("\n");
	return (0);
}
