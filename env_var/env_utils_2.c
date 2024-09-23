/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 08:08:27 by zqouri            #+#    #+#             */
/*   Updated: 2024/09/23 12:42:45 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    **empty_env(void)
{
    char   **env;
    char    *str;

    str = getcwd(NULL, 0);
    env = (char **)malloc(sizeof(char *) * 4);
    if (!env)
        ft_error("malloc failed\n");
    env[0] = ft_strjoin("PWD=", str);
    env[1] = ft_strdup("SHLVL=0");
    env[2] = ft_strdup("_=/usr/bin/env");
    env[3] = NULL;
    return (env);
}

t_env	*ft_env_new_(char *key, char *value)
{
	t_env	*new;

	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->name = ft_strdup(key);
	new->value = ft_strdup(value);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_env	*ft_env_new(char *env)
{
	t_env	*new;
	char	*equal;

	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	equal = ft_strchr(env, '=');
	new->name = ft_substr(env, 0, equal - env);
	new->value = ft_strdup(equal + 1);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_env   *find_env(t_env *env, char *name)
{
    t_env   *tmp;

    tmp = env;
    while (tmp)
    {
        if (ft_strncmp(tmp->name, name, ft_strlen(tmp->name)) == 0)
            return (tmp);
        tmp = tmp->next;
    }
    return (NULL);
}
