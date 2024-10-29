/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 03:50:43 by zqouri            #+#    #+#             */
/*   Updated: 2024/10/29 08:00:06 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_home(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	if (tmp)
	{
		while (tmp)
		{
			if (ft_strncmp(tmp->name, "HOME", 5) == 0)
				return (tmp->value);
			tmp = tmp->next;
		}
	}
	return (NULL);
}

int	cd_error(char *path, int flag)
{
	if (flag == 0)
	{
		ft_putstr_fd("cd: error retrieving current directory: getcwd: cannot ",
			STDERR_FILENO);
		ft_putstr_fd("access parent directories: No such file or directory\n",
			STDERR_FILENO);
	}
	else if (flag == 1 && path)
	{
		ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
		ft_putstr_fd(path, STDERR_FILENO);
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
	}
	return (1);
}

int	ft_cd(t_cmd *cmd, t_env *env, char *old_pwd, char *path)
{
	int	st;

	st = 0;
	old_pwd = getcwd(NULL, 0);
	if (!cmd->args[1])
	{
		if ((chdir(get_home(env)) == -1 && !cmd->args[1]) || !get_home(env))
		{
			ft_putstr_fd("minishell: cd: HOME not set\n", STDERR_FILENO);
			st = 1;
		}
		else
			st = 0;
	}
	if (cmd->args[1] && (!ft_strcmp(cmd->args[1], ".")
			|| !ft_strcmp(cmd->args[1], "..")))
	{
		chdir((const char *)cmd->args[1]);
		st = 0;
	}
	else if (chdir((const char *)cmd->args[1]) == -1)
		st = cd_error(cmd->args[1], 1);
	path = getcwd(NULL, 0);
	if (!path)
		st = cd_error(NULL, 0);
	ft_change_env(env, "OLDPWD", old_pwd);
	ft_change_env(env, "PWD", path);
	free(old_pwd);
	free(path);
	return (st);
}
