/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 00:12:17 by zqouri            #+#    #+#             */
/*   Updated: 2024/08/24 16:59:52 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init(t_cmd *cmd_list)
{
	char	**args;
	
	args = ft_split(cmd_list->ful_cmd, ' ');
	cmd_list->pipe_line = 1;
	cmd_list->cmd = ft_strdup(args[0]);
	cmd_list->args = args;
	cmd_list->fd_in = 0;
	cmd_list->fd_out = 1;
	
}

void	ft_init_pars(t_cmd **cmd_list, char *line)
{
	char	**args;
	int		size;
	int		i;
	t_cmd	*new;

	size = 0;
	i = 1;
	args = ft_split(line, '|');
	while (args[size] != NULL)
		size++;
	*cmd_list = ft_lstnew_cmd(args[0]);
	(*cmd_list)->pipe_line = size;
	while (args[i] != NULL)
	{
		new = ft_lstnew_cmd(args[i]);
		new->pipe_line = size;
		ft_lstadd_back_cmd(cmd_list, new);
		i++;
	}
}

void	affiche_node(t_cmd *cmd_list)
{
	t_cmd	*tmp;

	tmp = cmd_list;
	while (tmp)
	{
		printf("ful_cmd: %s		\n", tmp->ful_cmd);
		printf("pipe_line: %d		\n", tmp->pipe_line);
		printf("cmd:%s			\n", tmp->cmd);
		while (*tmp->args)
		{
			printf("args: %s		\n", *tmp->args);
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
