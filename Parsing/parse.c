/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 01:28:07 by mohmazou          #+#    #+#             */
/*   Updated: 2024/08/01 00:25:48 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_add_space(char **line)
{
	int		i;
	char	*new_line;
	int		j;
	
	i = 0;
	j = 0;
	(void)line;
	(void)new_line;
	while ((*line)[i])
	{
		if ((*line)[i] == '(' || (*line)[i] == ')' || (*line)[i] == ';' || (*line)[i] == '|')
			j += 2;
		i++;
	}
	j += i;
}


t_cmd	*ft_parse_line(char *line)
{
	t_cmd	*cmd_list;
	char	**all_tokens;

	
	cmd_list = NULL;
	//check line
	if (ft_check_syntax(line) == 0)
	{
		printf("syntax error\n");
		return (NULL);
	}

	printf("syntax ok : $$ %s\n", line);
	//add extra space 
	// ft_add_space(&line);
	
	//tokenizing
	all_tokens = tokenizing(line);
	//affich tokens
		// for (int i = 0; all_tokens[i]; i++)
		// {
		// 	printf("%s\n", all_tokens[i]);
		// }
	return (cmd_list);
}