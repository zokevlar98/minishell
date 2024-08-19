/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanding2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 00:45:30 by mohmazou          #+#    #+#             */
/*   Updated: 2024/08/19 06:55:10 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/minishell.h"

int	not_expandable(char c)
{
	return ((c >= '0' && c <= '9') || c == '@');
}

int	is_expandable(char c)
{
	static int	inside_dq;
	static int	inside_sq;

	if (c == '\'' && !inside_dq)
		inside_sq = !inside_sq;
	if (c == '\"' && !inside_sq)
		inside_dq = !inside_dq;
	return (c == '$' && !inside_sq);	
}

char	*ft_expend(char *str,t_env *env_list)
{
	char	*new_str;
	int		status;
	int		i;
	int		j;
(void)env_list;
	i = 0;
	j = 0;
	new_str = ft_malloc(MAX_TOKENS * 75, 0);
	if (!new_str)
		return (NULL);
	while (str[i])
	{
		status = is_expandable(str[i]);
		if (status && str[i + 1] == '?')
		{
			new_str = ft_strjoin(new_str, "EXIT_STATUS");
			j = j + ft_strlen("EXIT_STATUS");
		}
		else if (status && not_expandable(str[i + 1]))
			i ++;
		else if (status && (ft_isalnum(str[i + 1]) || str[i + 1] == '_'))
		{
			new_str = ft_strjoin(new_str, "{EXPANDING}");
			j = j + ft_strlen("{EXPANDING}");
			while (str[i + 1] && (ft_isalnum(str[i + 1]) || str[i + 1] == '_'))
				i ++;
			
		}
		else
			new_str[j++] = str[i];
		i ++;
	}
	
	return (new_str);
}


void	ft_expend_cmd(t_cmd *cmd,t_env *env_list)
{
	int	i;
	char	*tmp;
	
	i = 0;
	while (cmd->cmd && cmd->cmd[i])
	{
		if (ft_strchr(cmd->cmd[i], '$'))
		{
			tmp = cmd->cmd[i];
			cmd->cmd[i] = ft_expend(cmd->cmd[i], env_list);
			free(tmp);
		}
		i ++;
	}
	i = 0;
	while (cmd->in_redir && cmd->in_redir[i])
	{
		if (ft_strchr(cmd->in_redir[i], '$'))
		{
			tmp = cmd->in_redir[i];
			cmd->in_redir[i] = ft_expend(cmd->in_redir[i], env_list);
			free(tmp);
		}
		i ++;
	}
	i = 0;
	while (cmd->out_redir && cmd->out_redir[i])
	{
		if (ft_strchr(cmd->out_redir[i], '$'))
		{
			tmp = cmd->out_redir[i];
			cmd->out_redir[i] = ft_expend(cmd->out_redir[i], env_list);
			free(tmp);
		}
		i ++;
	}
}

void	ft_expending(t_cmd *cmd_list,t_env *env_list)
{
	t_cmd	*tmp;

	tmp = cmd_list;
	while (tmp)
	{

		ft_expend_cmd(tmp, env_list);
		tmp = tmp->next;
	}
}

