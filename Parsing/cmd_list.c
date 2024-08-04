/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 23:10:43 by mohmazou          #+#    #+#             */
/*   Updated: 2024/08/04 02:46:22 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void affich_cmd_list(t_cmd *cmd_list)
{
	t_cmd *tmp;
	int i;
	int j;

	tmp = cmd_list;
	i = 1;
	while (tmp)
	{
		printf("=====================================\n");
		
		
		printf("cmd [%d]\t: %s\n", i, tmp->cmd);
		printf("pipe\t: %d\n", tmp->pipe_line);
		j = 0;
		while (tmp->args && tmp->args[j])
		{
			if (!j) printf("args : \n");
			printf("\targ[%d]\t: %s\n", j, tmp->args[j]);
			j++;
		}
		j = 0;
		while (tmp->in_redir && tmp->in_redir[j])
		{
			if (!j) printf("in_redir :\n");
			printf("\tin_redir[%d]\t: %s\n", j, tmp->in_redir[j]);
			j++;
		}
		j = 0;
		while (tmp->out_redir && tmp->out_redir[j])
		{
			if (!j) printf("out_redir :\n");
			printf("\tout_redir[%d]\t: %s\n", j, tmp->out_redir[j]);
			j++;
		}
		printf("next\t: %p\n", tmp->next);

		
		printf("=====================================\n");
		tmp = tmp->next;
		i++;
	}
}

t_cmd	*ft_new_cmd(int pipe)
{
	t_cmd	*new_cmd;

	new_cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new_cmd)
		return (NULL);
	new_cmd->pipe_line = pipe;
	new_cmd->cmd = NULL;
	new_cmd->args = NULL;
	new_cmd->in_redir = NULL;
	new_cmd->out_redir = NULL;
	new_cmd->next = NULL;
	return (new_cmd);
}

void	ft_add_cmd(t_cmd **cmd_list, t_cmd *new_cmd)
{
	t_cmd	*tmp;

	if (!new_cmd)
		return ;
	if (!*cmd_list)
		*cmd_list = new_cmd;
	else
	{
		tmp = *cmd_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_cmd;
	}
}

char **add_to_array(char **array, char *str) {
    int count = 0;
	
    while (array && array[count])
		count++;

    array[count] = strdup(str);
    array[count + 1] = NULL;

    return array;
}

void	ft_fill_cmd_list(t_cmd **cmd_list, char **all_tokens, int pipe)
{
	t_cmd	*new_cmd;
	int		i;
	int 	j;

	i = 0;
	j = 0;
	(void)pipe;
	(void)cmd_list;
	new_cmd = NULL;
	while (i <= pipe)
	{
		if (ft_strcmp(all_tokens[j], "|") != 0)
			new_cmd = ft_new_cmd(i);
		while (all_tokens[j] && ft_strcmp(all_tokens[j], "|") != 0)
		{
			if (!new_cmd->cmd && all_tokens[j][0] != '<' && all_tokens[j][0] != '>')
				new_cmd->cmd = ft_strdup(all_tokens[j]);
			else if (all_tokens[j][0] == '<')
			{
				if (!new_cmd->in_redir)
					new_cmd->in_redir = (char **)malloc(sizeof(char *) * MAX_TOKENS);
				new_cmd->in_redir = add_to_array(new_cmd->in_redir, all_tokens[j]);
			}
			else if (all_tokens[j][0] == '>')
			{
				if (!new_cmd->out_redir) 
					new_cmd->out_redir = (char **)malloc(sizeof(char *) * MAX_TOKENS);
				new_cmd->out_redir = add_to_array(new_cmd->out_redir, all_tokens[j]);
			}
			else
			{
				if (!new_cmd->args)
					new_cmd->args = (char **)malloc(sizeof(char *) * MAX_TOKENS);
				new_cmd->args = add_to_array(new_cmd->args, all_tokens[j]);
			}
			j ++;
		}
		ft_add_cmd(cmd_list, new_cmd);
		new_cmd = NULL;
		j++;
		i++;
	}
	
	affich_cmd_list(*cmd_list);
	// cmd_list->next = NULL;
	// return (cmd_list);
}

