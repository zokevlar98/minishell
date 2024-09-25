
#include "minishell.h"

char	*get_ex(t_env *env, char *line, int i)
{
	char	*name;
	char	*value;

	name = ft_get_name(line, i);
	value = ft_env_search(env, name);
	return (value);
}

void	join_val(t_env *env, char *line, char *new_line, int *j)
{
	char	*ex_v;
	int		i;
	int		k;

	i = 0;
	k = 0;
	ex_v = get_ex(env, line, i);
	if (ex_v)
	{
		while (ex_v[k])
		{
			new_line[*j] = ex_v[k];
			(*j)++;
			k++;
		}
	}
}

t_utils	*intialize_utils(int len)
{
	t_utils	*u;

	u = (t_utils *)ft_malloc(sizeof(t_utils), 0);
	u->fd = 0;
	u->i = 0;
	u->j = 0;
	u->f_name = NULL;
	u->status = 0;
	u->len = len;
	return (u);
}

int	fill_str(t_env *env, char *line, char *new_line)
{
	t_utils	*u;

	u = intialize_utils(ft_strlen(line));
	while (u->i < u->len)
	{
		u->status = is_expandable(line[u->i]);
		if (u->status && line[u->i + 1] && line[u->i + 1] != ' ')
			u->i++;
		if (line[u->i] && u->status && line[u->i] == '?')
			join_exit(new_line, "0", &u->j, &u->i);
		else if (line[u->i] && u->status && not_expandable(line[u->i]))
			u->i++;
		else if (line[u->i] && u->status && ft_to_ex(line[u->i]))
		{
			join_val(env, line + u->i, new_line, &u->j);
			while (line[u->i] && ft_to_ex(line[u->i]))
				u->i++;
		}
		else
		{
			new_line[u->j++] = line[u->i++];
		}
			
	}
	return (0);
}

char	*expd_line(char *line, t_env *env)
{
	char	*new_line;
	int		len;

	if (!line)
		return (NULL);
	if (line[0] == '\0')
		return (NULL);
	len = new_len(line, env);
	new_line = allocat_zero(len + 1);
	if (fill_str(env, line, new_line) == -1)
		return (NULL);
	return (new_line);
}
