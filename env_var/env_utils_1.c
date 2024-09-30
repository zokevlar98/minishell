/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 21:21:42 by zqouri            #+#    #+#             */
/*   Updated: 2024/09/30 12:40:36 by zqouri           ###   ########.fr       */
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

t_env	*ft_lstlast_env(t_env *env)
{
	t_env	*last;

	if (!env)
		return (NULL);
	last = env;
	while (last->next)
		last = last->next;
	return (last);
}

void	ft_env_add_back(t_env **env, t_env *new)
{
	t_env	*last;

	if (!env || !new)
		return ;
	if (*env)
	{
		last = ft_lstlast_env(*env);
		if (!last)
			return ;
		last->next = new;
	}
	else
		(*env) = new;
}

void	ft_env_list(t_env **env_list, char **env)
{
	int		i;
	int		j;
	int		flag;
	t_env	*new;

	i = 0;
	j = 0;
	flag = 0;
	new = NULL;
	if (!env)
		return ;
	while (env[j])
	{
		if (ft_strcmp(env[j], "OLDPWD") == 0)
			flag = 1;
		j++;
	}
	if (!flag)
	{
		new = ft_env_new_("OLDPWD", NULL);
		ft_env_add_back(env_list, new);
	}
	// the problem is here i gonna to add a flag to check if the OLDPWD is already exist flag=0 & flag=1
	// while (env[j])
	// 	j++;
	// if (j == 4)
	// {//modifie becouse of if i unset the OLDPWD is not removed
	// 	new = ft_env_new_("OLDPWD", NULL);
	// 	ft_env_add_back(env_list, new);
	// }
	while (env[i])
	{
		new = ft_env_new(env[i]);
		if (!new)
			ft_error("error: failed");
		ft_env_add_back(env_list, new);
		i++;
	}
}
