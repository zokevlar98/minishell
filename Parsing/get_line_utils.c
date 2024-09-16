/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:31:03 by mohmazou          #+#    #+#             */
/*   Updated: 2024/09/16 19:14:20 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	in_qote(int *sq, int *dq, char c)
{
	if (c == '\'' && !(*dq))
		*sq = !(*sq);
	if (c == '\"' && !(*sq))
		*dq = !(*dq);
}

char	**get_in_rd(char *line, int dq, int sq)
{
	char	**in_rd;
	int		i;
	int		j;
	int		count;

	count = ft_cnt_red(line, '<');
	in_rd = ft_malloc(sizeof(char *) * (count + 1), 0);
	i = -1;
	j = 0;
	while (line[++i])
	{
		if (line[i] == '\'' && !dq)
			sq = !sq;
		if (line[i] == '\"' && !sq)
			dq = !dq;
		if (line[i] == '<' && !dq && !sq)
		{
			in_rd[j] = get_redir(line, i);
			j++;
			if (line[i + 1] == '<')
				i++;
		}
	}
	in_rd[j] = NULL;
	return (in_rd);
}

char	**get_out_rd(char *line, int dq, int sq)
{
	char	**out_rd;
	int		i;
	int		j;
	int		count;

	count = ft_cnt_red(line, '>');
	out_rd = ft_malloc(sizeof(char *) * (count + 1), 0);
	i = -1;
	j = 0;
	while (line[++i])
	{
		if (line[i] == '\'' && !dq)
			sq = !sq;
		if (line[i] == '\"' && !sq)
			dq = !dq;
		if (line[i] == '>' && !dq && !sq)
		{
			out_rd[j] = get_redir(line, i);
			j++;
			if (line[i + 1] == '>')
				i++;
		}
	}
	out_rd[j] = NULL;
	return (out_rd);
}
