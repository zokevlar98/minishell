/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 01:28:07 by mohmazou          #+#    #+#             */
/*   Updated: 2024/08/02 08:23:23 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		nbr_pipe(char **tokens)
{
	int i;
	int pipe;

	i = 0;
	pipe = 0;
	while (tokens[i])
	{
		if (tokens[i][0] == '|')
			pipe++;
		i++;
	}
	return (pipe);
}

char **add_to_array(char **array, char *str) {
    int count = 0;
    while (array && array[count])
		count++;

    array[count] = strdup(str);
    array[count + 1] = NULL;

    return array;
}

t_cmd	*ft_fill_cmd_list(char **all_tokens, int pipe)
{
	t_cmd	*cmd_list;
	t_cmd	*new_cmd;
	int		i;
	int 	j;

	i = 0;
	j = 0;
	cmd_list = NULL;
	while (i <= pipe)
	{
		if (all_tokens[j][0] != '|')
		{
			new_cmd = malloc(sizeof(t_cmd));
			if (!new_cmd)
				return (NULL);
			new_cmd->pipe_line = i;
			new_cmd->cmd = NULL;
			new_cmd->next = NULL;
			new_cmd->args = NULL;
			new_cmd->in_redir = NULL;
			new_cmd->out_redir = NULL;
		}
		// printf("SIG FAULT\n");
		while (all_tokens[j] && all_tokens[j][0] != '|')
		{
			if (all_tokens[j][0] == '<')
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
			else if (!new_cmd->cmd)
				new_cmd->cmd = ft_strdup(all_tokens[j]);
			else
				new_cmd->args = add_to_array(new_cmd->args, all_tokens[j]);
			
			j ++;
		}
		if (!cmd_list)
			cmd_list = new_cmd;
		else
		{
			cmd_list->next = new_cmd;
			cmd_list = cmd_list->next;
		}
		
		i++;
	}
	// cmd_list->next = NULL;
	return (cmd_list);
}

char	**re_tokenizing(char **all_tokens)
{
	char	**new_tokens;
	int		i;
	int		j;
	
	(void)all_tokens;
	i = 0;
	j = 0;
	new_tokens = malloc(sizeof(char *) * MAX_TOKENS);
	if (!new_tokens)
		return (NULL);
	while (all_tokens[i])
	{
		if (ft_strcmp(all_tokens[i], ">>") == 0 || ft_strcmp(all_tokens[i], "<<") == 0 || ft_strcmp(all_tokens[i], ">") == 0 || ft_strcmp(all_tokens[i], "<") == 0)
		{
			new_tokens[j] = ft_strjoin(all_tokens[i], all_tokens[i + 1]);
			i ++;
			j++;
		}
		else
		{
			new_tokens[j] = ft_strdup(all_tokens[i]);
			j++;
		}
		i ++;
	}
	new_tokens[j] = NULL;
	return (new_tokens);
}

t_cmd	*ft_parse_line(char *line)
{
	t_cmd	*cmd_list;
	char	**all_tokens;
	int		i;
	
	
	
	cmd_list = NULL;
	i = 0;
	//check line
	if (ft_check_syntax(line) == 0)
	{
		printf("syntax error : %s\n", line);
		return (NULL);
	}
	
	
	//tokenizing
	all_tokens = tokenizing(ft_add_space(line, i));
	if (!ft_check_tokens(all_tokens))
	{
		printf("syntax error : %s\n", line);
		return (NULL);
	}
	all_tokens = re_tokenizing(all_tokens);
	cmd_list = ft_fill_cmd_list(all_tokens, nbr_pipe(all_tokens));
	//affich tokens
		// for (int i = 0; all_tokens[i]; i++)
		// {
		// 	printf("token[%d] --%s--\n",i , all_tokens[i]);
		// }
	
	// affich cmd_list

	while (cmd_list)
	{
		printf("pipe_line : %d\n", cmd_list->pipe_line);
		printf("cmd : %s\n", cmd_list->cmd);
		if (cmd_list->args)
		{
			for (int i = 0; cmd_list->args[i]; i++)
			{
				printf("args[%d] --%s--\t",i , cmd_list->args[i]);
			}
		}
		if (cmd_list->in_redir)
		{
			for (int i = 0; cmd_list->in_redir[i]; i++)
			{
				printf("in_redir[%d] --%s--\t",i , cmd_list->in_redir[i]);
			}
		}
		if (cmd_list->out_redir)
		{
			for (int i = 0; cmd_list->out_redir[i]; i++)
			{
				printf("out_redir[%d] --%s--\n",i , cmd_list->out_redir[i]);
			}
		}
		printf("\n--------------------------------\n");
		cmd_list = cmd_list->next;
	}
	
	
	return ((t_cmd *)1);
}