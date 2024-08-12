/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 09:00:37 by zqouri            #+#    #+#             */
/*   Updated: 2024/08/12 04:53:16 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_list_declare(t_env *env)
{
	while (env)
	{
		printf("declare -x %s=\"%s\"\n", env->name, env->value);
		env = env->next;
	}
}

void	ft_export(t_cmd *cmd, t_env *env)
{
	t_env	*tmp;
	t_env	*new;
	char	**str;

	tmp = env;
	if (!cmd->args[1])
	{
		print_list_declare(tmp);
		return ;
	}
	while (tmp)
	{
		if (ft_strncmp(tmp->name, cmd->args[1], ft_strlen(tmp->name)) == 0)
		{
			str = ft_split(cmd->args[1], '=');
			affiche_node(cmd);
			ft_change_env(env, str[1], str[2]);
			return ;
		}
		tmp = tmp->next;
	}
	if (ft_strchr(cmd->args[1], '='))
	{
		str = ft_split(cmd->args[1], '=');
		new = ft_env_new_(str[0], str[1]);
		if (!new)
			ft_error("error: feailed");
		ft_env_add_back(&tmp, new);
		return ;
	}
	else
		printf("9ewada export\n");
}
