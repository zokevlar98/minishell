/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:08:40 by zqouri            #+#    #+#             */
/*   Updated: 2024/10/28 12:57:17 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	affiche_cmd(t_cmd *cmd)
{
	int	i;
	t_cmd	*tmp;

	tmp = cmd;
	while (tmp)
	{
		printf("pipe_line = %d \n", tmp->pipe_line);
		i = 0;
		while (tmp->args[i])
		{
			printf("args[%d] = %s \n", i, tmp->args[i]);
			i++;
		}
		printf("fd_in = %d \n", tmp->fd_in);
		printf("fd_out = %d \n", tmp->fd_out);
		printf("***************************\n");
		tmp = tmp->next;
	}
}

void	get_exit_status(int status)
{
	if (WIFEXITED(status))
		g_data = WEXITSTATUS(status);
	if (WIFSIGNALED(status))
	{
		g_data = 128 + WTERMSIG(status);
		if (g_data == 131)
			ft_putstr_fd("Quit: 3\n", 1);
	}
}
