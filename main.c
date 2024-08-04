/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 23:17:58 by mohmazou          #+#    #+#             */
/*   Updated: 2024/08/04 07:52:13 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_execut_cmd(t_cmd *cmd_list, t_env *env_list)
{
	affich_cmd_list(cmd_list);
	printf("env USER : %s\n", ft_env_search(env_list, "USER"));
}

void	start_loop(t_env *env_list)
{
	char	*line;
	t_cmd	*cmd_list;

	while (1)
	{
		line = readline("minishell$>  ");
		if (!line && ft_strcmp(line, "exit") == 0 && line[0] != '\0')
			break ;
		if (line[0] != '\0')
			add_history(line);
		else
			continue ;
		cmd_list = ft_parse_line(line);
		if (!cmd_list)
		{
			free(line);
			continue ;
		}
		ft_execut_cmd(cmd_list, env_list);
		free(line);
	}
}

int	main(int ac, char **av, char **env)
{
	t_env	*env_list;

	env_list = NULL;
	ft_env_list(&env_list, env);
	if (ac != 1 || av[1])
	{
		printf("Usage: %s\n", av[0]);
		return (1);
	}
	start_loop(env_list);
	return (0);
}
