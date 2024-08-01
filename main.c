/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 23:17:58 by mohmazou          #+#    #+#             */
/*   Updated: 2024/08/01 04:45:00 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **av, char **env)
{
	char *line;
	t_env *env_list;

	env_list = NULL;
	ft_env_list(&env_list, env);
	t_cmd *cmd_list = (t_cmd *)malloc(sizeof(t_cmd));
	if (ac != 1 || av[1])
	{
		printf("Usage: %s\n", av[0]);
		return (1);
	}
	while (1)
	{
		line = readline("minishell$>  ");
		if (!line)
			break;
		if (line[0] != '\0')
			add_history(line);
		cmd_list->cmd = line;
		ft_execut_cmd(cmd_list, env_list);
		// printf("%s\n", line);
		free(line);
	}
	// cmd_list->ful_cmd = "";
	// cmd_list->pipe_line = 0;
	// cmd_list->args[0] = "-la";
	// cmd_list->in_redir = NULL;
	// cmd_list->out_redir = NULL;
	// cmd_list->next = NULL;
	// printf("hello\n");
	return (0);
}