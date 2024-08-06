/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 23:39:06 by mohmazou          #+#    #+#             */
/*   Updated: 2024/08/06 06:42:07 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_env_search(t_env *env_list, char *name)
{
	t_env	*tmp;

	tmp = env_list;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, name))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}


static t_env	*ft_env_new(char *env)
{
	t_env	*new;
	char	*equal;

	new = ft_malloc(sizeof(t_env), 0);
	if (!new)
		return (NULL);
	equal = ft_strchr(env, '=');
	new->name = ft_substr(env, 0, equal - env);
	new->value = ft_strdup(equal + 1);
	new->next = NULL;
	return (new);
}

static void	ft_env_add_back(t_env **env_list, t_env *new)
{
	t_env	*tmp;

	if (!*env_list)
	{
		*env_list = new;
		return ;
	}
	tmp = *env_list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	ft_env_list(t_env **env_list,char **env)
{
	int		i;
	t_env	*new;
	
	i = 0;
	new = NULL;
	while (env[i])
	{
		new = ft_env_new(env[i]);
		ft_env_add_back(env_list, new);
		i++;
	}
}