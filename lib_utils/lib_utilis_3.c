/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utilis_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:32:05 by mohmazou          #+#    #+#             */
/*   Updated: 2024/09/21 06:31:51 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	**append_args(char **args)
{
	int		i;
	int		j;
	int		size;
	char	**new_args;
	
	size = 0;
	j = 0;
	i = 2;
	while (ft_strncmp(args[i], ''))
		i++;
	while (args[size])
		size++;
	new_args = (char **)malloc(sizeof(char *) * (size + 2));
	if (!new_args)
		return (NULL);
	new_args[0] = args[0];
	new_args[1] = ft_strdup("-G");
	while (args[i] != NULL)
	{
		new_args[i] = args[i];
		i++;
	}
	new_args[i] = NULL;
	return (new_args);
}
