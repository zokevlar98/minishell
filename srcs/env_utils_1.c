/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 23:39:06 by mohmazou          #+#    #+#             */
/*   Updated: 2024/07/31 00:43:14 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char *ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

static t_env	*ft_env_new(char *env)
{
	t_env	*new;
	char	*equal;

	new = malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	equal = ft_strchr(env, '=');
	new->name = ft_substr(env, 0, equal - env);
	new->value = ft_strdup(equal + 1);
	new->next = NULL;
	return (new);
}

void	ft_env_list(t_env **env_list,char **env)
{
	int		i;
	t_env	*new;

	i = 0;
	new = NULL;
	while (env[i])
	{
		new = ft_env_new(env[i]);
		ft_env_add_back(env_list, new);
		i++;
	}
	
}