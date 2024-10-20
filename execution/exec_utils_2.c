/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 19:57:41 by zqouri            #+#    #+#             */
/*   Updated: 2024/10/21 14:28:19 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*check_path(char **path_s, char *cmd)
{
	int		i;
	char	*path;

	i = 0;
	while (path_s[i])
	{
		path = ft_strjoin(path_s[i], "/");
		path = ft_strjoin(path, cmd);
		if (access(path, F_OK) == 0)
			return (ft_free(path_s), path);
		i++;
	}
	return (NULL);
}

char	*find_path_env(char *cmd, char *envp[])
{
	char	**path_s;
	char	*path;
	int		i;

	i = 0;
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, F_OK) == 0)
			return (cmd);	
	}
	else
	{
		path = ft_strjoin(getcwd(NULL, 0), "/");
		path = ft_strjoin(path, cmd);
		if (access(path, F_OK) == 0)
			return (path);
	}
	while (ft_strncmp(envp[i], "PATH", 4) != 0)
		i++;
	if (!envp[i])
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(cmd, STDERR_FILENO);
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	path_s = ft_split(envp[i] + 5, ':');
	path = check_path(path_s, cmd);
	return (path);
}

char	**ft_get_envp(t_env *env_list)
{
	t_env	*tmp;
	char	**envp;	
	int		i;

	tmp = env_list;
	i = 0;
	envp = (char **)malloc(sizeof(char *) * (count_env(tmp) + 1));
	if (!envp)
		return (NULL);
	while (tmp)
	{
		if (!tmp->value)
			envp[i] = ft_strdup(tmp->name);
		else
		{
			envp[i] = ft_strjoin(tmp->name, "=");
			envp[i] = ft_strjoin(envp[i], tmp->value);
		}
		tmp = tmp->next;
		i++;
	}
	envp[i] = NULL;
	return (envp);
}
