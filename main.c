/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 23:17:58 by mohmazou          #+#    #+#             */
/*   Updated: 2024/08/08 02:37:04 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **av, char **env)
{
	// char	*line;
	t_env	*env_list;
	t_cmd	*first_cmd;
	t_cmd	*second_cmd;

	env_list = NULL;
	ft_env_list(&env_list, env);
	t_cmd *cmd_list = (t_cmd *)malloc(sizeof(t_cmd));
	if (ac != 1 || av[1])
	{
		printf("Usage: %s\n", av[0]);
		return (1);
	}
	first_cmd = ft_lstnew();
	second_cmd = ft_lstnew();
	ft_lstadd_back(&cmd_list, first_cmd);
	ft_lstadd_back(&cmd_list, second_cmd);
	ft_init(first_cmd);
	ft_init_second(second_cmd);
	ft_execut_cmd(cmd_list, env_list);
	// while (1)
	// {
	// 	line = readline("minishell$>  ");
	// 	if (!line)
	// 		break;
	// 	if (line[0] != '\0')
	// 		add_history(line);
	// 	cmd_list->cmd = line;
	// 	// printf("%s\n", line);
	// 	free(line);
	// }
	return (0);
}
