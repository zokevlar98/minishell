/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanding_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:53:19 by mohmazou          #+#    #+#             */
/*   Updated: 2024/09/17 01:14:29 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	new_len(char *line)
{
	int		len;

	len = ft_strlen(line) + (c_ex(line) * MAX_TOKENS * 2);
	return (len);
}

void	*allocat_zero(size_t size)
{
	void	*ptr;

	// ptr = ft_malloc(size, 0);
	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, size);
	return (ptr);
}

int	ft_cnt_red(char *line, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == c)
		{
			count++;
			if (line[i + 1] == c)
				i++;
		}
		i++;
	}
	return (count);
}

void	join_exit(char *new_line, char *str, int *j, int *i)
{
	int	k;

	k = 0;
	while (str[k])
	{
		new_line[*j] = str[k];
		(*j)++;
		k++;
	}
	new_line[*j] = '\0';
	(*i)++;
}
