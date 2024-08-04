/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 23:17:58 by mohmazou          #+#    #+#             */
/*   Updated: 2024/08/04 06:33:35 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"


int allocation_count = 0;

void	ft_ext(void)
{
	system("leaks minishell");
}

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

	atexit(ft_ext);

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
		line = readline("minishell$>  ");
		if (!line)
			break;
		if (line[0] != '\0')
			add_history(line);
		else
			continue;
		if (ft_strcmp(line, "exit") == 0 && line[0] != '\0')
			break;
		cmd_list = ft_parse_line(line);
		if (!cmd_list)
		{
			free(line);
			continue;
		}
		affich_cmd_list(cmd_list);
		
		// ft_execut_cmd(cmd_list, env_list);
		free(line);
	}
	return (0);
}

// int main()
// {
// 	int i = 0;
// 	char **str = (char **)ft_malloc(100 * sizeof(char *));
// 	while (i < 100)
// 	{
// 		str[i] = "hello";
// 		i++;
// 	}
// 	printf("3mrat\n");
// 	i = 0;
// 	while (str[i])
// 	{
// 		printf("%s\n", str[i]);
// 		i++;
// 	}
// 	while (1)
// 	{
// 		/* code */
// 	}
	
	
	
// 	// ft_free_all();
// 	// atexit(ft_ext);
// 	return 0;
// }