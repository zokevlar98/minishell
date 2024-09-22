/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utilis_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:32:05 by mohmazou          #+#    #+#             */
/*   Updated: 2024/09/22 04:17:13 by zqouri           ###   ########.fr       */
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
	int		k;
	int		size;
	char	**new_args;

	j = 0;
	k = 1;
	i = 2;
	size = 0;
	while (ft_strncmp(args[j], "-G", ft_strlen(args[j])) == 0)
		return (args);
	while (args[size])
		size++;
	new_args = (char **)malloc(sizeof(char *) * (size + 2));
	if (!new_args)
		return (NULL);
	new_args[0] = ft_strdup(args[0]);
	new_args[1] = ft_strdup("-G");
	while (args[k] != NULL)
		new_args[i++] = ft_strdup(args[k++]);
	new_args[i] = NULL;
	return (ft_free(args) ,new_args);
}
