
#include "minishell.h"

int	all_space(char *line)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		if (line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	if (!s || n == 0)
		return ;
	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

int	exit_status(int status)
{
	static int	exit_status;

	if (status != -1)
		exit_status = status;
	return (exit_status);
}