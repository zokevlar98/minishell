/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_space.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 04:21:11 by mohmazou          #+#    #+#             */
/*   Updated: 2024/08/01 05:01:35 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


int	new_size(char *line)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (line[i])
	{
		if (line[i] == '<' || line[i] == '>')
			size += 2;
		else if (line[i] == '|')
			size += 3;
		else
			size++;
		i++;
	}
	return (size);
}

char	*ft_add_space(char *line, int i)
{
	char	*new_line;
	int		j;
	int		single_quote;
	int		double_quote;

	new_line = (char *)malloc(new_size(line) + 1);
	j = 0;
	single_quote = 0;
	double_quote = 0;
	while (line[i])
	{
		in_quotes(line[i], &single_quote, &double_quote);
		if ((line[i] == '<' || line[i] == '>') && !single_quote && !double_quote)
		{
			if (i && line[i - 1] != ' ' && line[i - 1] != '<' && line[i - 1] != '>')
				new_line[j++] = ' ';
			new_line[j++] = line[i];
		}
		else if (line[i] == '|' && !single_quote && !double_quote)
		{
			if (i && line[i - 1] != ' ')
				new_line[j++] = ' ';
			new_line[j++] = line[i];
			new_line[j++] = ' ';
		}
		else
			new_line[j++] = line[i];
		i++;
	}
	new_line[j] = '\0';
	return (new_line);
}