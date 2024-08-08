/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 00:12:17 by zqouri            #+#    #+#             */
/*   Updated: 2024/08/08 02:34:07 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init(t_cmd *cmd_list)
{
	cmd_list->ful_cmd = ft_strdup("ls -la");
	cmd_list->pipe_line = 1;
	cmd_list->cmd = ft_strdup("ls");
	cmd_list->args = ft_split(" -la ", ' ');
	cmd_list->in_redir = NULL;
	cmd_list->out_redir = NULL;
}

void	ft_init_second(t_cmd *cmd_list)
{
	cmd_list->ful_cmd = ft_strdup("wc -l");
	cmd_list->pipe_line = 1;
	cmd_list->cmd = ft_strdup("wc");
	cmd_list->args = ft_split(" -l ", ' ');
	cmd_list->in_redir = NULL;
	cmd_list->out_redir = NULL;
}
