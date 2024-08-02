/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 23:17:58 by mohmazou          #+#    #+#             */
/*   Updated: 2024/08/01 08:20:31 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_execut_cmd(t_cmd *cmd_list, t_env *env_list)
{
	(void)cmd_list;
	// printf("cmd : %s\n", cmd_list->cmd);
	printf("env USER : %s\n", ft_env_search(env_list, "USER"));
}

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
		// if (av[1])
		// 	line = ft_strdup("echo \"Hello World\"");
		// else
			line = readline("miishell$>  ");
		if (!line)
			break;
		if (line[0] != '\0')
			add_history(line);
		else
			continue;
		cmd_list = ft_parse_line(line);
		if (!cmd_list)
		{
			free(line);
			continue;
		}
		
		// ft_execut_cmd(cmd_list, env_list);
		free(line);
	}
	return (0);
}