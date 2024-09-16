/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 04:01:55 by mohmazou          #+#    #+#             */
/*   Updated: 2024/09/16 20:46:46 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	affich_cmd_list(t_cmd *cmd_list)
{
	int	i;

	while (cmd_list)
	{
		printf("\n-------------\n\n");
		printf("pipe_line = %d\n", cmd_list->pipe_line);
		i = 0;
		if (cmd_list->args)
		{
			printf("args : \n");
			while (cmd_list->args[i])
			{
				printf("\targs[%d] = `%s`\n", i, cmd_list->args[i]);
				i++;
			}
		}
		printf("fd_in = %d\n", cmd_list->fd_in);
		printf("fd_out = %d\n", cmd_list->fd_out);
		printf("\n-------------\n\n");
		cmd_list = cmd_list->next;
	}
}

int	ft_add(char *line)
{
	if (!line)
	{
		printf("exit\n");
		ft_malloc(0, 1);
		exit(0);
	}
	if (line[0] == '\0' || all_space(line))
		return (1);
	if (!ft_check_syntax(line))
	{
		printf("syntax error\n");
		add_history(line);
		return (1);
	}
	add_history(line);
	return (0);
}

void	start_loop(t_env *env_list)
{
	char	*line;
	t_p_cmd	*cp_list;
	t_cmd	*cmd_list;

	while (1)
	{
		line = readline("minishell$>  ");
		if (ft_add(line))
		{
			free(line);
			continue ;
		}
		if (ft_strcmp(line, "exit") == 0)
		{
			free(line);
			break ;
		}
		ft_parsing(line, &cp_list, env_list);
		cmd_list = NULL;
		ft_merge(&cmd_list, cp_list, env_list);
		free(line);
	}
}

int	main(int ac, char **av, char **env)
{
	t_env	*env_list;

	if (ac != 1 || av[1])
		return (write(2, "Error: no arguments needed\n", 27));
	env_list = NULL;
	ft_env_list(&env_list, env);
	// ft_handle_signals();
	start_loop(env_list);
	ft_malloc(0, 1);
	return (0);
}
