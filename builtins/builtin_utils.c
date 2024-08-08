/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 04:02:26 by zqouri            #+#    #+#             */
/*   Updated: 2024/08/08 04:37:31 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** 1. ft_echo
** 2. ft_cd
** 3. ft_pwd
** 4. ft_export
** 5. ft_unset
** 6. ft_env
** 7. ft_exit
*/

int	is_caracter(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

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
		//eho
		i++;
	}
	ft_putstr_fd("\n", 1);
}
