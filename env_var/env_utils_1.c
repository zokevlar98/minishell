/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 21:21:42 by zqouri            #+#    #+#             */
/*   Updated: 2024/09/21 03:33:04 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_change_env(t_env *env_list, char *name, char *value)
{
	t_env	*tmp;

	tmp = env_list;
	if (!name || !value)
		return ;
	while (tmp)
	{
		if (ft_strncmp(tmp->name, name, ft_strlen(tmp->name)) == 0)
		{
			// free(tmp->value);// if this line is uncommented, the program  will double free becouse of ft_malloc i need a solution
			tmp->value = ft_strdup(value);
			return ;
		}
		tmp = tmp->next;
	}
	if (!tmp)
	{
		tmp = ft_env_new_(name, value);
		ft_env_add_back(&env_list, tmp);
	}
	free(value);
}

char	*ft_env_search(t_env *env_list, char *name)
{
	t_env	*tmp;

	tmp = env_list;
	while (tmp)
	{
		if (!ft_strncmp(tmp->name, name, ft_strlen(tmp->name)))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

void	ft_env_add_back(t_env **env_list, t_env *new)
{
	t_env	*tmp;

	if (!new)
		return ;
	if (!*env_list)
	{
		*env_list = new;
		return ;
	}
	tmp = *env_list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

void	ft_env_list(t_env **env_list, char **env)
{
	int		i;
	t_env	*new;

	i = 0;
	new = NULL;
	if (!env)
		return ;
	while (env[i])
	{
		new = ft_env_new(env[i]);
		if (!new)
			ft_error("error: failed");
		ft_env_add_back(env_list, new);
		i++;
	}
}
