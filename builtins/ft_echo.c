/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri < zqouri@student.1337.ma >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:44:35 by zqouri            #+#    #+#             */
/*   Updated: 2024/08/29 08:31:04 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(t_cmd *cmd_list)
{
	int		i;
	char	**cmd;

	i = 1;
	cmd = cmd_list->args;
	while (cmd[i])
	{
		//tanchouf blan expend
		// while (cmd[i][0] == '$')
		// {
		// 	cmd[i] = ft_get_env(cmd[i] + 1);
		// 	i++;
		// }
		if (is_caracter(cmd[i] , '"'))
		{
			cmd[i] = ft_strtrim(cmd[i], "\"");
			ft_putstr_fd(cmd[i], 1);
		}
		else if (is_caracter(cmd[i], '\''))
		{
			cmd[i] = ft_strtrim(cmd[i], "\'");
			ft_putstr_fd(cmd[i], 1);
		}
		else
			ft_putstr_fd(cmd[i], 1);
		i++;
	}
	ft_putstr_fd("\n", 1);
}
