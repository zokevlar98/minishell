/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 03:07:19 by zqouri            #+#    #+#             */
/*   Updated: 2024/10/25 03:38:28 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strdup_(const char *s)
{
	char	*dup;
	size_t	i;

	if (!s)
		return (NULL);
	i = -1;
	// dup = (char *)ft_malloc(sizeof(char) * (ft_strlen(s) + 1), 0);
    dup = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
    if (!dup)
        return (NULL);
	while (s[++i])
		dup[i] = s[i];
	dup[i] = '\0';
	return (dup);
}

char	*ft_substr_(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup("\0"));
	i = 0;
	// sub = (char *)ft_malloc(sizeof(char) * (len + 1), 0);
    sub = (char *)malloc(sizeof(char) * (len + 1));
    if (!sub)
        return (NULL);
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

void    ft_lst_clear_env(t_env **env)
{
    t_env    *tmp;
    t_env    *next;

    tmp = *env;
    while (tmp)
    {
        next = tmp->next;
        free(tmp->name);
        free(tmp->value);
        free(tmp);
        tmp = next;
    }
    *env = NULL;
}
