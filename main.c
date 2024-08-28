/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 09:51:55 by zqouri            #+#    #+#             */
/*   Updated: 2024/08/28 06:41:17 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//I need to change the index fd to macro for good practice 

int main(int ac, char **av, char **env)
{
	char *line;
	t_env *env_list;

	if (!env[0])
		env = empty_env();
	t_cmd *cmd_list = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd_list)
		ft_error("allocation failed");
	env_list = NULL;
	ft_env_list(&env_list, env);
	
	if (ac != 1 || av[1])
	{
		printf("Usage: %s\n", av[0]);
		return (1);
	}
	shell_lvl(env_list);
	while (1)
	{
		line = readline("minishell$>  ");
		if (!line)
			break;
		if (line[0] != '\0')
			add_history(line);

		ft_init_pars(&cmd_list, line);
		// ft_init(cmd_list);
		// affiche_node(cmd_list);
		ft_execut_cmd(cmd_list, &env_list);
		free(line);
	}
	return (0);
}
