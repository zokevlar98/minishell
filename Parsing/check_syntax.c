/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:27:43 by mohmazou          #+#    #+#             */
/*   Updated: 2024/08/02 04:06:10 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_check_quote(char *line)
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
	i = 0;
	return (!(quote || dquote || bracket));
}

void	in_quotes(char line_i, int *single_quote, int *double_quote)
{
	if (line_i == '\'' && (*double_quote) == 0)
		(*single_quote) = !(*single_quote);
	else if (line_i == '\"' && (*single_quote) == 0)
		(*double_quote) = !(*double_quote);
	// return (!(*single_quote) && !(*double_quote));
}

int skip_whitespace(char *line, int i)
{
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	return (i);
}

void ft_in_quotes(char c, int *single_quote, int *double_quote) {
    if (c == '\'' && !(*double_quote)) {
        *single_quote = !(*single_quote);
    } else if (c == '"' && !(*single_quote)) {
        *double_quote = !(*double_quote);
    }
}

int	ft_check_direction(char *line, int *single_quote, int *double_quote, char direction, char opposite)
{
	int	i;
	int	counter;
	int quote;
	int dquote;

 (void)single_quote;
 (void)double_quote;
	quote = 0;
	dquote = 0;
	i = 0;
	while (line[i])
	{
		// in_quotes(line[i], single_quote, double_quote);
		ft_in_quotes(line[i],&quote , &dquote);
		// printf("quote %d dquote %d\n", quote, dquote);
		if (quote == 0 && dquote == 0)
		{
			// printf("line_%d : %c\n", i, line[i]);
			i = skip_whitespace(line, i);
			ft_in_quotes(line[i],&quote , &dquote);
			if (line[i] && line[i] == direction)
			{
				counter = 0;
				while (line[i] == direction && line[i])
				{
					counter++;
					i++;
				}
				if (counter > 2)
					return (0);
				i = skip_whitespace(line, i);
				if (line[i] && line[i] == direction)
					return (0);
				if (line[i] == opposite)
					return (0);
				if (!line[i])
					return (0);
			}
		}
		if (line[i])
			i++;
	}
	return (1);
}

int		ft_check_syntax(char *line)
{
	int	single_quote;
	int	double_quote;

	single_quote = 0;
	double_quote = 0;
	
	line = ft_strtrim(line, " ");
	line = ft_strtrim(line, "\t");
	
	if (line[0] == '|')
		return (0);
	if (!ft_check_quote(line))
		return (0);
	if (!ft_check_direction(line, &single_quote, &double_quote , '>', '<'))
		return (0);
	if (!ft_check_direction(line, &single_quote, &double_quote , '<', '>'))
		return (0);
	
	return (1);
}