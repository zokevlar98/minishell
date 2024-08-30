/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:12:12 by mohmazou          #+#    #+#             */
/*   Updated: 2024/08/30 16:12:13 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "includes/minishell.h"

void	ft_execut_cmd(t_cmd *cmd_list, t_env *env_list)
{
	
	affich_cmd_list(cmd_list);
	(void)env_list;
}

void	start_loop(t_env *env_list)
{
	char	*line;
	t_p_cmd	*cmd_p_list;
	t_cmd	*cmd_list;

	while (1)
	{
		line = readline("minishell$>  ");
		if (line[0] != '\0')
			add_history(line);
		else
		{
			free(line);
			continue ;
		}
		cmd_p_list = ft_parse_line(line, env_list);
		if (!cmd_p_list)
		{
			free(line);
			continue ;
		}
		ft_expending(cmd_p_list, env_list);
		// affich_cmd_p_list(cmd_p_list);
		cmd_list = ft_p_cmd_to_cmd(cmd_p_list);
		open_file(cmd_p_list, cmd_list);
		ft_execut_cmd(cmd_list, env_list);
		free(line);
	}
}

void	ft_leaks(void)
{
	system("leaks minishell");
}
//expand case didnt work :
/*
$"USER"
$'USER'

*/
int	main(int ac, char **av, char **env)
{
	t_env	*env_list;

	atexit(ft_leaks);
	env_list = NULL;
	ft_env_list(&env_list, env);
	if (ac != 1 || av[1])
	{
		printf("Usage: %s\n", av[0]);
		return (1);
	}
	start_loop(env_list);
	ft_malloc(0, 1);
	return (0);
}
