/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 03:38:16 by mohmazou          #+#    #+#             */
/*   Updated: 2024/07/29 02:04:47 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int   checking_line(char *line)
{
	int	i;
	int	dquote;
	int	quote;
	int	brackets;

	i = 0;
	dquote = 0;
	quote = 0;
	brackets = 0;
	while (line[i])
	{
		if (line[i] == '\"')
			dquote++;
		if (line[i] == '\'')
			quote++;
		if (line[i] == '(')
			brackets++;
		if (line[i] == ')')
			brackets--;
		i++;
	}
	if (dquote % 2 != 0 || quote % 2 != 0 || brackets != 0)
		return (0);
	return (1);
}

void	ft_minishell(char *line, t_env *env_lst, t_cmd **cmd)
{
	char	**cmd_lines;
	(void)env_lst;
	(void)cmd;

	cmd_lines = ft_split(line, '|');
	ft_cdmlst(cmd, cmd_lines);
	// int i = 0;
	// while (cmd_lines[i])
	// {
	// 	printf("cmd_lines[%d] : %s\n", i, cmd_lines[i]);
	// 	i++;
	// }
	
	
	
	// printf("commad line : %s\n", line);
}