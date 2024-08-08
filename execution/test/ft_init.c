/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 00:12:17 by zqouri            #+#    #+#             */
/*   Updated: 2024/08/08 04:37:50 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init(t_cmd *cmd_list)
{
	cmd_list->ful_cmd = ft_strdup("echo 'hello'");
	cmd_list->pipe_line = 0;
	cmd_list->cmd = ft_strdup("echo");
	cmd_list->args = ft_split("echo 'hello' ", ' ');
	cmd_list->in_redir = NULL;
	cmd_list->out_redir = NULL;
}

void	ft_init_second(t_cmd *cmd_list)
{
	cmd_list->ful_cmd = ft_strdup("wc -l");
	cmd_list->pipe_line = 1;
	cmd_list->cmd = ft_strdup("wc");
	cmd_list->args = ft_split("wc -l ", ' ');
	cmd_list->in_redir = NULL;
	cmd_list->out_redir = NULL;
}

void	affiche_node(t_cmd *cmd_list)
{
	t_cmd	*tmp;

	tmp = cmd_list;
	while (tmp)
	{
		printf("ful_cmd: %s		|\n", tmp->ful_cmd);
		printf("pipe_line: %d		|\n", tmp->pipe_line);
		printf("cmd: %s			|\n", tmp->cmd);
		while (*tmp->args)
		{
			printf("args: %s		|\n", *tmp->args);
			tmp->args++;
		}
		printf("-------------------------\n");
		tmp = tmp->next;
	}
}

void	print_args(char **args)
{
	while (*args)
	{
		printf("%s\n", *args);
		args++;
	}
}
