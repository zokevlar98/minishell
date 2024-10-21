/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 03:57:23 by zqouri            #+#    #+#             */
/*   Updated: 2024/10/21 03:32:05 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	affiche_env(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	if (tmp)
	{
		while (tmp)
		{
			printf("%s=%s\n", tmp->name, tmp->value);
			tmp = tmp->next;
		}
	}	
}

void	ff(void)
{
	system("leaks minishell");
	// system("lsof -c minishell");
}
