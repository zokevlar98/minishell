/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_space.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 04:21:11 by mohmazou          #+#    #+#             */
/*   Updated: 2024/08/08 17:27:31 by mohmazou         ###   ########.fr       */
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

// void ft_complete(char line_c, char *new_line, int in_quot )
// {
// 	if ((line[i] == '<' || line[i] == '>') && !(*s_q) && !(*d_q))
// 	{
// 		if (i && line[i - 1] != ' ' && line[i - 1] != '<' && line[i - 1] != '>')
// 			new_line[j++] = ' ';
// 		new_line[j++] = line[i];
// 	}
// }

void	ft_add_space_completing(char *line, char *new_line, int *s_q, int *d_q)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		in_quotes(line[i], s_q, d_q);
		if ((line[i] == '<' || line[i] == '>') && !(*s_q) && !(*d_q))
		{
			if (i && line[i - 1] != ' '
				&& line[i - 1] != '<' && line[i - 1] != '>')
				new_line[j++] = ' ';
			new_line[j++] = line[i];
		}
		else if (line[i] == '|' && !(*s_q) && !(*d_q))
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
}

char	*ft_add_space(char *line)
{
	char	*new_line;
	int		single_quote;
	int		double_quote;

	new_line = (char *)ft_malloc(new_size(line) + 1, 0);
	single_quote = 0;
	double_quote = 0;
	ft_add_space_completing(line, new_line, &single_quote, &double_quote);
	return (new_line);
}
