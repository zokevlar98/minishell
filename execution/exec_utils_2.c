/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 19:57:41 by zqouri            #+#    #+#             */
/*   Updated: 2024/08/02 20:26:54 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_path_env(char *cmd, char *envp[])
{
	char	**path_s;
	char	*path;
	int		i;
	char	*tmp;

	i = 0;
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, F_OK) == 0)
			return (cmd);
	}
	while (ft_strncmp(envp[i], "PATH", 4) != 0)
		i++;
	path_s = ft_split(envp[i] + 5, ':');
	i = 0;
	while (path_s[i++])
	{
		tmp = ft_strjoin(path_s[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
	}
	return (ft_free(path_s), NULL);
}

char	**ft_get_envp(t_env *env_list)
{
	t_env	*tmp;
	char	**envp;	
	int		i;

	i = 0;
	tmp = env_list;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	envp = (char **)malloc(sizeof(char *) * (i + 1));
	if (!envp)
		return (NULL);
	i = 0;
	tmp = env_list;
	while (tmp)
	{
		envp[i] = ft_strjoin(tmp->name, "=");
		envp[i] = ft_strjoin(envp[i], tmp->value);
		tmp = tmp->next;
		i++;
	}
	envp[i] = NULL;
	return (envp);
}
