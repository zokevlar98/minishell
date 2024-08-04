/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 01:28:07 by mohmazou          #+#    #+#             */
/*   Updated: 2024/08/04 04:51:39 by mohmazou         ###   ########.fr       */
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
	ft_fill_cmd_list(&cmd_list, all_tokens, nbr_pipe(all_tokens));
	
	

	
	
	
	return (cmd_list);
}