/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_red.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:36:45 by mohmazou          #+#    #+#             */
/*   Updated: 2024/09/17 01:14:03 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_red_pattern(char *line, int *i)
{
	int	j;

	j = *i;
	if (line[j] == '<' && line[j + 1] == '<')
		j += 2;
	else if (line[j] == '>' && line[j + 1] == '>')
		j += 2;
	else if (line[j] == '<' || line[j] == '>')
		j++;
	else
		return (0);
	while (line[j] && line[j] == ' ')
		j++;
	if (line[j] == '|')
		return (0);
	if (!line[j] || (line[j] == '<' || line[j] == '>'))
		return (0);
	*i = j - 1;
	return (1);
}

int	ft_check_direction(char *line)
{
	int	single_quote;
	int	double_quote;
	int	i;

	single_quote = 0;
	double_quote = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '\'' && !double_quote)
			single_quote = !single_quote;
		else if (line[i] == '"' && !single_quote)
			double_quote = !double_quote;
		else if ((line[i] == '<' || line[i] == '>')
			&& !single_quote && !double_quote)
		{
			if (!check_red_pattern(line, &i))
				return (1);
		}
		i++;
	}
	return (0);
}
