/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 23:44:30 by mohmazou          #+#    #+#             */
/*   Updated: 2024/07/28 23:50:03 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_count_words(char *str, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
		if (str[i])
			i++;
	}
	return (count);
}

char	*ft_get_word(char *str, char c)
{
	int		i;
	char	*word;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char c)
{
	char	**tab;
	int		i;
	int		j;

	tab = (char **)malloc(sizeof(char *) * (ft_count_words(str, c) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			tab[j] = ft_get_word(str + i, c);
			if (!tab[j])
				return (NULL);
			while (str[i] && str[i] != c)
				i++;
		}
		j++;
		if (str[i])
			i++;
	}
	tab[j] = NULL;
	return (tab);
}