/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 23:17:58 by mohmazou          #+#    #+#             */
/*   Updated: 2024/07/31 01:12:55 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int main(int ac, char **av, char **env)
{
	char *line;
	t_env *env_list;

	(void)env;
	env_list = NULL;
	ft_env_list(&env_list, env);
	if (ac != 1 || av[1])
	{
		printf("Usage: %s\n", av[0]);
		return (1);
	}
	while (1)
	{
		line = readline("miishell$>  ");
		if (!line)
			break;
		if (line[0] != '\0')
			add_history(line);
		printf("%s\n", line);
		free(line);
	}
	return (0);
}