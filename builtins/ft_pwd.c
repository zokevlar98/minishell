/*  ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 08:24:10 by zqouri            #+#    #+#             */
/*   Updated: 2024/08/11 08:45:59 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(t_env *env)
{
	char	*path;

	path = getcwd(NULL, 0);
	if (path)
	{
		ft_putstr_fd(path, STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
		free(path);
	}
	else if (ft_env_search(env, "PWD"))
	{
		ft_putstr_fd(ft_env_search(env, "PWD"), STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
	else if (ft_env_search(env, "OLDPWD"))
	{
		ft_putstr_fd(ft_env_search(env, "OLDPWD"), STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
	else
		ft_putstr_fd("minishell: pwd:", STDERR_FILENO);
}