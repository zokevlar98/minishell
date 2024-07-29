/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 01:04:28 by mohmazou          #+#    #+#             */
/*   Updated: 2024/07/29 04:17:33 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void free_cmdlst(t_cmd *cmd)
{
	t_cmd *tmp;
	
	while (cmd)
	{
		tmp = cmd;
		cmd = cmd->next;
		free(tmp->ful_cmd);
		// free(tmp->cmd);
		// free(tmp->args);
		// free(tmp->in_redir);
		// free(tmp->out_redir);
		free(tmp);
	}
	cmd = NULL;
}

char	*ft_rmv_space(char *str)
{
	int		start;
	int		end;
	int		i;
	char	*new_str;
	
	start = 0;
	i = 0;
	while (str[start] && str[start] == ' ')
		start++;
	end = ft_strlen(str) - 1;
	while (str[end] && str[end] == ' ')
		end--;
	new_str = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!new_str)
		ft_error("malloc error");
	while (start <= end)
	{
		new_str[i] = str[start];
		i++;
		start++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_get_cmd(char *cmd_lines)
{
	char	*cmd;
	int		i;
	
	i = 0;
	
	// while (cmd_lines[i] && cmd_lines[i] != ' ')
	// 	i++;
	cmd = (char *)malloc(sizeof(char) * (i + 1));
	if (!cmd)
		ft_error("malloc error");
	i = 0;
	while (cmd_lines[i] && cmd_lines[i] != ' ')
	{
		cmd[i] = cmd_lines[i];
		i++;
	}
	cmd[i] = '\0';
	return (cmd);
}

char	*ft_get_outredir(char *cmd_lines)
{
	int		i;
	int		j;
	char	*in_redir;
	
	i = 0;
	while (cmd_lines[i] && cmd_lines[i] != '>')
		i++;
	j = i;
	while (cmd_lines[j] && cmd_lines[j] != ' ')
		j++;
	in_redir = (char *)malloc(sizeof(char) * (j - i + 1));
	j = 0;
	while (cmd_lines[i] && cmd_lines[i] != ' ')
	{
		in_redir[j] = cmd_lines[i];
		i++;
		j++;
	}
	in_redir[j] = '\0';
	return (in_redir);
}

char	*ft_get_inredir(char *cmd_lines)
{
	int		i;
	int		j;
	char	*out_redir;
	
	i = 0;
	while (cmd_lines[i] && cmd_lines[i] != '<')
		i++;
	j = i;
	while (cmd_lines[j] && cmd_lines[j] != ' ')
		j++;
	out_redir = (char *)malloc(sizeof(char) * (j - i + 1));
	j = 0;
	while (cmd_lines[i] && cmd_lines[i] != ' ')
	{
		out_redir[j] = cmd_lines[i];
		i++;
		j++;
	}
	out_redir[j] = '\0';
	return (out_redir);
}

t_cmd	*lst_new_cmd(char *cmd_lines, int i)
{
	printf("dral hna %i\n", i);
	printf("dral hna %s\n", cmd_lines);
	t_cmd *new_cmd;
	
	new_cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new_cmd)
		ft_error("malloc error");
	new_cmd->ful_cmd = ft_strdup(cmd_lines);
	new_cmd->pipe_line = i;
	new_cmd->cmd = ft_get_cmd(cmd_lines);
	// new_cmd->args = ft_split(cmd_lines, ' ');
	new_cmd->in_redir = ft_get_inredir(cmd_lines);
	new_cmd->out_redir = ft_get_outredir(cmd_lines);
	new_cmd->next = NULL;
	return (new_cmd);
}

void	ft_add_last_cmd(t_cmd **cmd, t_cmd *new_cmd)
{
	t_cmd *tmp;
	
	if (!*cmd)
	{
		*cmd = new_cmd;
		return ;
	}
	tmp = *cmd;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_cmd;
}

void	ft_cdmlst(t_cmd **cmd,char **cmd_lines)
{
	int i = 0;
	t_cmd *new_cmd;
	
	while (cmd_lines[i])
	{
		new_cmd = lst_new_cmd(ft_rmv_space(cmd_lines[i]), i);
		ft_add_last_cmd(cmd, new_cmd);
		i ++;
	}

	
}