
#include "minishell.h"

int	is_expandable(char c)
{
	static int	inside_dq;
	static int	inside_sq;

	if (c == '\'' && !inside_dq)
		inside_sq = !inside_sq;
	if (c == '\"' && !inside_sq)
		inside_dq = !inside_dq;
	return (c == '$' && !inside_sq);
}

char	*ft_get_name(char *str, int i)
{
	char	*name;
	int		j;

	j = i;
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
		i ++;
	name = ft_substr(str, j, i - j);
	return (name);
}

int	c_ex(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str && str[i])
	{
		if (str[i] == '$' && (ft_to_ex(str[i + 1]) || str[i + 1] == '?'))
			count ++;
		i ++;
	}
	return (count);
}

int	not_expandable(char c)
{
	return ((c >= '0' && c <= '9') || c == '@');
}

int	ft_to_ex(char c)
{
	return (ft_isalnum(c) || c == '_');
}
