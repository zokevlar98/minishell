/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:38:28 by zqouri            #+#    #+#             */
/*   Updated: 2024/10/20 22:34:08 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_env_var(char *var, int flag)
{
	int	i;

	i = 0;
	while (var[i])
	{
		if (i == 0 && ft_isdigit(var[i]) && var[i] != '_')
			return (0);
		if (var[i] == '+' && var[i + 1] != '\0')
		{
			if  (flag == 0)
			{
				if (var[i + 1] == '=')
					return (i + 1);
			}
			else if (flag == 1)
				return (-1);
		}
		if (!ft_isalnum(var[i]) && var[i] != '_' && var[i] != '=')
			return (0);
		if (var[i] == '=')
			return (i);
		i++;
	}
	return (i);
}

void	update_var(t_env **env, char *name, char *value, int flag)
{
	t_env	*var;

	var = find_env(*env, name);
	if (!var)
	{
		var = ft_env_new_(name, value);
		ft_env_add_back(env, var);
	}
	else
	{
		if (var->value && value)
		{
			if (flag == 0)
			{
				free(var->value);
				var->value = ft_strdup(value);
			}
			else if (flag == 1)
				var->value = ft_strjoin(var->value, value);
		}
		else
		{
			if (flag == 0)
				var->value = ft_strdup(value);
			else if (flag == 1)
			var->value = ft_strdup(value);
		}
	}
}

void	add_var_env(char *var, t_env **env)
{
	int		size_name;
	int		size_value;
	char	*name;
	char	*value;

	size_name = check_env_var(var, 0);
	if (!size_name)
		return ;
	name = ft_substr(var, 0, size_name);
	size_value = size_name;
	while (var[size_name] == '=' && var[size_value])
		size_value++;
	value = ft_substr(var, size_name + 1, size_value);
	if (ft_strlen(value) == 0)
		value = NULL;
	if (check_env_var(var, 1) == -1)
		update_var(env, name, value, 1);//append
	else
		update_var(env, name, value, 0);//update
}

void	ft_export(t_cmd *cmd, t_env **env)
{
	int		i;
	//case export a=4 then export a => env: a
	// more check
	i = 1;
	if (!cmd->args[1])
	{
		print_list_declare(env);
		return ;
	}
	while (cmd->args[i])
	{
		if (!check_env_var(cmd->args[i], 0))
			ft_export_error(cmd->args[i]);
		else
			add_var_env(cmd->args[i], env);
		i++;
	}
}
