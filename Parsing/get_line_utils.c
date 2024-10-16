
#include "minishell.h"

void	in_qote(int *sq, int *dq, char c)
{
	if (c == '\'' && !(*dq))
		*sq = !(*sq);
	if (c == '\"' && !(*sq))
		*dq = !(*dq);
}

char	**get_rd(char *line, int dq, int sq)
{
	char	**rd;
	int		i;
	int		j;
	int		count;

	count = ft_cnt_red(line, '<') + ft_cnt_red(line, '>');
	rd = (char **)ft_malloc(sizeof(char *) * (count + 1), 0);
	i = -1;
	j = 0;
	while (line[++i])
	{
		if (line[i] == '\'' && !dq)
			sq = !sq;
		if (line[i] == '\"' && !sq)
			dq = !dq;
		if ((line[i] == '<' || line[i] == '>') && !dq && !sq)
		{
			rd[j] = get_redir(line, i);
			j++;
			if (line[i + 1] == '<' || line[i + 1] == '>')
				i++;
		}
	}
	rd[j] = NULL;
	return (rd);
}
