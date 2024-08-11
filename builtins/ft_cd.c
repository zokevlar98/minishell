/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 03:50:43 by zqouri            #+#    #+#             */
/*   Updated: 2024/08/11 03:53:43 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_home(t_env *env)
{
	t_env	*tmp;

	if (env)
	{
		
	}
}

void	ft_cd(t_cmd *cmd_list, t_env *env_list)
{
	char	*path;

	if (cmd_list->args[1] == NULL)
	{
		// grep home in env list
		if (chdir() == -1)
			ft_error("no such file or directory\n");
	}
	else if (chdir((const char *)cmd_list->args[1]) == -1)
		ft_error("no such file or directory\n");
	path = getcwd(NULL, 0);
	if (!path)
		ft_error("no such file or directory\n");
	ft_change_env(env_list, "PWD", path);
	free(path);
}
