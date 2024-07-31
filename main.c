/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 23:17:58 by mohmazou          #+#    #+#             */
/*   Updated: 2024/07/31 01:31:42 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int main(int ac, char **av, char **env)
{
	char *line;
	t_env *env_list;
	t_cmd *cmd_list;

	// initialize the env_list	
	env_list = NULL;
	ft_env_list(&env_list, env);
	
	cmd_list = NULL;
	// check for arguments
	if (ac != 1 || av[1])
	{
		printf("Usage: %s\n", av[0]);
		return (1);
	}
	
	// main loop
	while (1)
	{
		line = readline("miishell$>  ");
		if (!line)
			break;
		if (line[0] != '\0')
			add_history(line);
		cmd_list = ft_parse_line(line);
		printf("%s\n", line);
		// ft_execut_cmd(cmd_list, env_list);
		free(line);
	}
	return (0);
}