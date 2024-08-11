/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 03:56:00 by zqouri            #+#    #+#             */
/*   Updated: 2024/08/11 09:22:18 by zqouri           ###   ########.fr       */
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


void	ft_builtin(t_cmd *cmd_list, t_env *env_list)
{
	char	*cmd;
	
	cmd = lower_case(cmd_list->args[0]);
	if (ft_strncmp(cmd, "echo", ft_strlen("echo")) == 0)
		ft_echo(cmd_list);
	else if (ft_strncmp(cmd, "cd", ft_strlen("cd")) == 0)
		ft_cd(cmd_list, env_list);
	else if (ft_strncmp(cmd, "pwd", ft_strlen("pwd")) == 0)
		ft_pwd(env_list);
	else if (ft_strncmp(cmd, "env", ft_strlen("env")) == 0)
		ft_env(cmd_list, env_list);
	// else if (ft_strncmp(cmd, "export", ft_strlen("export")) == 0)
	// 	ft_export(cmd_list, env_list);
	// else if (ft_strncmp(cmd, "unset", ft_strlen("unset")) == 0)
	// 	ft_unset(cmd_list);
	// else if (ft_strncmp(cmd, "exit", ft_strlen("exit")) == 0)
	// 	ft_exit(cmd_list);
}
