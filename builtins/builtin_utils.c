/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 04:02:26 by zqouri            #+#    #+#             */
/*   Updated: 2024/09/16 01:12:12 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_caracter(char *str, char c)
{
	int	i;

	i = 0;
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
	// I need fonction to sort my ENV liked list
	// i well help me for case "export"
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
