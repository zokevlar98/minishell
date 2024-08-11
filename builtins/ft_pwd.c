/* ************************************************************************** */
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
		ft_putstr_fd(path, 1);
		ft_putstr_fd("\n", 1);
		free(path);
	}
	else if (ft_env_search(env, "PWD"))
	{
		ft_putstr_fd(ft_env_search(env, "PWD"), 1);
		ft_putstr_fd("\n", 1);
	}
	else if (ft_env_search(env, "OLDPWD"))
	{
		ft_putstr_fd(ft_env_search(env, "OLDPWD"), 1);
		ft_putstr_fd("\n", 1);
	}
	else
		ft_putstr_fd("minishell: pwd:", 2);
}
