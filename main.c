/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 04:01:55 by mohmazou          #+#    #+#             */
/*   Updated: 2024/10/22 14:49:23 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_data = 0;
// static int	exit_status;
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
		line = readline(GRN" -> "CYN"Minishell "RST);
		if (ft_add(line))
		{
			free(line);
			continue ;
		}
		ft_parsing(line, &cp_list, env_list);
		cmd_list = NULL;
		ft_merge(&cmd_list, cp_list, env_list);
		ft_execut_cmd(cmd_list, &env_list);
		free(line);
	}
}

int	main(int ac, char **av, char **env)
{
	t_env	*env_list;

	if (ac != 1 || av[1])
		return (write(2, "Error: no arguments needed\n", 27));
	if (!env[0])
		env = empty_env();
	env_list = NULL;
	ft_env_list(&env_list, env, 0);
	shell_lvl(env_list);
	//ft_handle_signals();
	start_loop(env_list);
	return (0);
}
