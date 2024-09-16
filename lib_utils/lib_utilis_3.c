/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utilis_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:32:05 by mohmazou          #+#    #+#             */
/*   Updated: 2024/09/10 17:44:55 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
