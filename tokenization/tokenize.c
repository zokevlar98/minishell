/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 06:02:09 by mohmazou          #+#    #+#             */
/*   Updated: 2024/07/31 07:08:45 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}


void	ft_toggle_flags(char c, int *in_double_quote, int *in_single_quote, int *in_parentheses)
{
	(void)in_parentheses;
	if (c == '"' && !*in_single_quote && !*in_parentheses)
		*in_double_quote = !*in_double_quote;
	else if (c == '\'' && !*in_double_quote && !*in_parentheses)
		*in_single_quote = !*in_single_quote;
	else if (c == '(' && !*in_double_quote && !*in_single_quote)
		(*in_parentheses)++;
	else if (c == ')' && !*in_double_quote && !*in_single_quote)
		(*in_parentheses)--;
}


void	**tokenize_line(char *line, char ***tokens, int length, int *in_double_quote, int *in_single_quote, int *in_parentheses)
{
	int		token_count;
	int		start;
	int		end;
	char	*token;

	token_count = 0;
	start = 0;
	end = 0;
	token = NULL;
	
	while (end <= length)
	{
		ft_toggle_flags(line[end], in_double_quote, in_single_quote, in_parentheses);
		if ((is_whitespace(line[end]) || line[end] == '\0') && !*in_double_quote && !*in_single_quote && !*in_parentheses)
		{
			if (start != end)
			{
				token = ft_substr(line, start, end - start);
				// *tokens = (char **)realloc(*tokens, sizeof(char *) * (token_count + 1));
				(*tokens)[token_count++] = token;
			}
			start = end + 1;
		}
		end++;
	}
	// *tokens = (char **)realloc(*tokens, sizeof(char *) * (token_count + 1));
	(*tokens)[token_count] = NULL;
	return NULL;
}

char	**tokenizing(char *line)
{
	char	**tokens;
	int		in_double_quote;
	int		in_single_quote;
	int		in_parentheses;

	in_double_quote = 0;
	in_single_quote = 0;
	in_parentheses = 0;
	tokens = (char **)malloc(sizeof(char *) * MAX_TOKENS);
	
	tokenize_line(line,&tokens , ft_strlen(line),&in_double_quote, &in_single_quote, &in_parentheses);
	
	return (tokens);
}