/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:18:12 by mohmazou          #+#    #+#             */
/*   Updated: 2024/09/16 19:14:04 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_utils	*ini_utls(char *line)
{
	t_utils	*u;

	u = ft_malloc(sizeof(t_utils), 0);
	u->new_line = ft_malloc(ft_strlen(line) + 1, 0);
	ft_bzero(u->new_line, ft_strlen(line) + 1);
	u->sq = 0;
	u->dq = 0;
	return (u);
}

char	*get_redir(char *line, int i)
{
	char	*redir;
	int		j;
	int		dq;
	int		sq;

	j = i;
	dq = 0;
	sq = 0;
	while (line[j] && (line[j] == '>' || line[j] == '<'))
		j++;
	while (line[j] && line[j] == ' ')
		j++;
	while (line[j])
	{
		if (line[j] == '\'' && !dq)
			sq = !sq;
		if (line[j] == '\"' && !sq)
			dq = !dq;
		if ((line[j] == ' ' || line[j] == '>' || line[j] == '<') && !dq && !sq)
			break ;
		j++;
	}
	redir = ft_substr(line, i, j - i);
	return (redir);
}

void	skip(char *line, int *i)
{
	if (line[(*i)] == '<' || line[(*i)] == '>')
		(*i)++;
	while (line[(*i)] && line[(*i)] == ' ')
		(*i)++;
}

char	*line_no_rd(char *line, int i, int j)
{
	t_utils	*u;

	u = ini_utls(line);
	while (line[i])
	{
		in_qote(&u->sq, &u->dq, line[i]);
		if ((line[i] == '<' || line[i] == '>') && !u->dq && !u->sq)
		{
			i ++;
			skip(line, &i);
			while (line[i])
			{
				in_qote(&u->sq, &u->dq, line[i]);
				if (line[i] == ' ' && !u->dq && !u->sq)
					break ;
				i++;
			}
		}
		else
			u->new_line[j++] = line[i];
		if (line[i])
			i++;
	}
	u->new_line[j] = '\0';
	return (u->new_line);
}

void	get_line(char *line, t_p_cmd *cp_list, t_env *env_list)
{
	char	*new_line;
	char	**in_rd;
	char	**out_rd;

	new_line = NULL;
	in_rd = NULL;
	out_rd = NULL;
	in_rd = get_in_rd(line, 0, 0);
	out_rd = get_out_rd(line, 0, 0);
	new_line = line_no_rd(line, 0, 0);
	if (ft_strchr(new_line, '$'))
		new_line = expd_line(new_line, env_list);
	cp_list->line = new_line;
	cp_list->in_redir = in_rd;
	cp_list->out_redir = out_rd;
	cp_list->cmd = ft_split_cmd(new_line, ' ', 0, 0);
}
