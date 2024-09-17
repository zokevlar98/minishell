/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:38:19 by mohmazou          #+#    #+#             */
/*   Updated: 2024/09/17 18:53:18 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*rm_qot(char *str, int s_q, int d_q)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	// new_str = ft_malloc(ft_strlen(str) + 1, 0);
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!new_str)
		return (NULL);
	ft_bzero(new_str, ft_strlen(str) + 1);
	while (str[i])
	{
		if (str[i] == '\'' && !d_q)
		{
			s_q = !s_q;
			i++;
		}
		else if (str[i] == '\"' && !s_q)
		{
			d_q = !d_q;
			i++;
		}
		else
			new_str[j++] = str[i++];
	}
	new_str[j] = '\0';
	return (new_str);
}

char	**ft_quoted_cmd(char **cmd)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!cmd)
		return (NULL);
	while (cmd[i])
	{
		tmp = rm_qot(cmd[i], 0, 0);
		cmd[i] = tmp;
		i++;
	}
	return (cmd);
}

t_cmd	*ft_new_cmd(t_p_cmd *cp_cmd, t_env *env_list)
{
	t_cmd	*new_cmd;

	// new_cmd = ft_malloc(sizeof(t_cmd), 0);
	new_cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new_cmd)
		return (NULL);
	new_cmd->pipe_line = cp_cmd->pipe_line;
	new_cmd->args = ft_quoted_cmd(cp_cmd->cmd);
	if (cp_cmd->in_redir && cp_cmd->in_redir[0])
		new_cmd->fd_in = open_in(cp_cmd->in_redir, env_list);
	else
		new_cmd->fd_in = 0;
	if (cp_cmd->out_redir && cp_cmd->out_redir[0])
		new_cmd->fd_out = open_out(cp_cmd->out_redir, env_list);
	else
		new_cmd->fd_out = 1;
	new_cmd->next = NULL;
	return (new_cmd);
}

void	cmd_add_back(t_cmd **cmd_list, t_cmd *new_cmd)
{
	t_cmd	*tmp;

	tmp = *cmd_list;
	if (!tmp)
	{
		*cmd_list = new_cmd;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_cmd;
}

void	close_tab(int *fd_tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		close(fd_tab[i]);
		i++;
	}
}
