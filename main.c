/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:39:16 by zqouri            #+#    #+#             */
/*   Updated: 2024/08/22 18:16:35 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//I need to change the index fd to macro for good practice 

int main(int ac, char **av, char **env)
{
	char	*line;
	t_env	*env_list;
	t_cmd	*first_cmd;
	// t_cmd	*second_cmd;
	// t_cmd	*theird_cmd;

	env_list = NULL;
	ft_env_list(&env_list, env);
	t_cmd *cmd_list = (t_cmd *)malloc(sizeof(t_cmd));
	if (ac != 1 || av[1])
	{
		printf("Usage: %s\n", av[0]);
		return (1);
	}
	first_cmd = ft_lstnew();
	// second_cmd = ft_lstnew();
	// theird_cmd = ft_lstnew();
	// ft_init_second(second_cmd);
	// ft_init_theird(theird_cmd);
	cmd_list = first_cmd;
	// ft_lstadd_back(&cmd_list, second_cmd);
	// ft_lstadd_back(&cmd_list, theird_cmd);
	// affiche_node(cmd_list);
	while (1)
	{
		line = readline("minishell$>  ");
		if (!line)
			break;
		if (line[0] != '\0')
			add_history(line);
		cmd_list->ful_cmd = line;
		ft_init(cmd_list);
		affiche_node(cmd_list);
		ft_execut_cmd(cmd_list, env_list);
		free(line);
	}
	return (0);
}
