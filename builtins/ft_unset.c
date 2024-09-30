/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri < zqouri@student.1337.ma >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:41:56 by zqouri            #+#    #+#             */
/*   Updated: 2024/08/13 18:41:56 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_unset_error(char *name)
{
	ft_putstr_fd("minishell: unset: `", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
}

int check_unset_var(char *name)
{
	int i;

	i = 0;
	while (name[i])
	{
		if (i == 0 && !ft_isalpha(name[i]) && name[i] != '_')
			return (0);
		if (!ft_isalnum(name[i]) && name[i] != '_')
			return (0);
		i++;
	}
	return (i);
}

void	remove_first_node(t_env **env)
{
	t_env	*tmp;

	tmp = (*env);
	(*env) = (*env)->next;
	if (tmp && tmp->name)
		free(tmp->name);
	if (tmp && tmp->value)
		free(tmp->value);
	if (tmp)
		free(tmp);
}

void	remove_env_var(t_env **env, char *name)
{
	t_env	*var;
	t_env	*next_var;

	//Initialization:
	var = (*env);
	next_var = (*env)->next;
	//check the first node :
	if ((*env) && ft_strcmp((*env)->name, name) == 0)
	{
		remove_first_node(env);
		return ;
	}
	//Traversal of the env linked list:
	while (next_var && ft_strcmp(next_var->name, name) != 0)
	{
		var = var->next;
		next_var = next_var->next;
	}
	//Unlinking the Node frome env linked list:
	var->next = next_var->next;
	//Free the Node:
	if (next_var && next_var->name)
		free(next_var->name);
	if (next_var && next_var->value)
		free(next_var->value);
	if (next_var)
		free(next_var);
}

void	ft_unset(t_cmd *cmd, t_env **env)
{
	int		i;
	t_env	*var;

	i = 1;
	if (!cmd->args[i] || !(*env))
		return ;
	while (cmd->args[i])
	{
		if (!check_unset_var(cmd->args[i]))
			ft_unset_error(cmd->args[i]);
		var = find_env(*env, cmd->args[i]);
		if (var)
			remove_env_var(env, var->name);
		i++;
	}
}
