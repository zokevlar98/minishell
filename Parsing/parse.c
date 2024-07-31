/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 01:28:07 by mohmazou          #+#    #+#             */
/*   Updated: 2024/07/31 02:02:07 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_check_line(char *line)
{
	int	quote;
	int	dquote;
	int	bracket;
	int	i;

	quote = 0;
	dquote = 0;
	bracket = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '\'' && dquote == 0)
			quote = !quote;
		if (line[i] == '\"' && quote == 0)
			dquote = !dquote;
		if (line[i] == '(' && quote == 0 && dquote == 0)
			bracket++;
		if (line[i] == ')' && quote == 0 && dquote == 0)
			bracket--;
		i++;
	}

	if (quote || dquote || bracket)
	{
		printf("Error: syntax error\n");
		return (0);
	}
	return (1);
}

t_cmd	*ft_parse_line(char *line)
{
	t_cmd	*cmd_list;
	t_cmd	*new_cmd;
	char	**all_tokens;
	int		i;

	(void)line;
	(void)all_tokens;
	(void)i;
	
	cmd_list = NULL;
	new_cmd = NULL;
	if (ft_check_line(line) == 0)
		return (NULL);
	
	
	return (cmd_list);
}