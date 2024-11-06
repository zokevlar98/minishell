/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 04:02:26 by zqouri            #+#    #+#             */
/*   Updated: 2024/11/06 17:56:20 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_caracter(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	shell_lvl(t_env *env)
{
	char	*value;
	int		shell_lvl;
	t_env	*new;

	value = ft_env_search(env, "SHLVL");
	if (!value)
	{
		new = ft_env_new("SHLVL=1");
		ft_env_add_back(&env, new);
		return ;
	}
	shell_lvl = ft_atoi(value);
	shell_lvl++;
	ft_change_env(env, "SHLVL", ft_itoa(shell_lvl));
}

int	max_index(t_cmd *cmd)
{
	while (cmd->next)
		cmd = cmd->next;
	return (cmd->pipe_line);
}

int	is_ne_one(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '-' && str[i + 1] == '1')
			return (1);
		i++;
	}
	return (0);
}
