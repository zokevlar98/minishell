/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_up.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 03:30:53 by zqouri            #+#    #+#             */
/*   Updated: 2024/08/11 02:08:22 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_up_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	ft_up_count_word(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == ' ' || s[i] == '\t')
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] && (s[i] != ' ' && s[i] != '\t'))
			i++;
	}
	return (count);
}

char	*ft_up_word(char *s, size_t *idx)
{
	int		i;
	int		word_len;
	char	*tab;

	i = 0;
	word_len = 0;
	while (s[*idx] && (s[*idx] == ' ' || s[*idx] == '\t'))
		(*idx)++;
	if (s[*idx])
	{
		i = *idx;
		while (s[*idx] && (s[*idx] != ' ' && s[*idx] != '\t'))
		{
			(*idx)++;
			word_len++;
		}
	}
	tab = (char *)malloc(sizeof(char) * (word_len + 1));
	if (!tab)
		return (NULL);
	word_len = 0;
	while (s[i] && (s[i] != ' ' && s[i] != '\t'))
		tab[word_len++] = s[i++];
	tab[word_len] = '\0';
	return (tab);
}

char	**ft_split_up(char *s)
{
	int		i;
	int		count;
	size_t	idx;
	char	**dest;

	if (!s)
		return (NULL);
	i = 0;
	count = ft_up_count_word(s);
	dest = (char **)malloc(sizeof(char *) * (count + 1));
	if (!dest)
		return (NULL);
	idx = 0;
	while (i < count)
	{
		dest[i] = ft_up_word(s, &idx);
		if (dest[i] == NULL)
			return (ft_up_free(dest), NULL);
		i++;
	}
	dest[i] = NULL;
	return (dest);
}
