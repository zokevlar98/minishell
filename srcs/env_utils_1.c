/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 04:07:35 by mohmazou          #+#    #+#             */
/*   Updated: 2024/07/29 01:48:37 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_env_befor(char *str)
{
	int		i;
	char	*name;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	name = (char *)malloc(sizeof(char) * (i + 1));
	if (!name)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '=')
	{
		name[i] = str[i];
		i++;
	}
	name[i] = '\0';
	return (name);
}

char	*ft_env_after(char *str)
{
	int		i;
	int		y;
	char	*value;

	i = 0;
	y = 0;
	while (str[i] && str[i] != '=')
		i++;
	if (!str[i])
		return (NULL);
	i++;
	value = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!value)
		return (NULL);
	while (str[i])
	{
		value[y] = str[i];
		i++;
		y++;
	}
	value[y] = '\0';
	return (value);
}

void	ft_add_last(t_env **env_lst, t_env *new)
{
	t_env	*tmp;

	tmp = *env_lst;
	if (!tmp)
	{
		*env_lst = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_env	*lst_new(char *str)
{
	t_env	*new;

	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->name = ft_env_befor(str);
	new->value = ft_env_after(str);
	new->next = NULL;
	return (new);
}

void	ft_envlst(char **env, t_env **env_lst)
{
	int		i;
	t_env	*new;
(void)env;
(void)env_lst;
	i = 0;
	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		return ;
	// new->name = ft_strdup("mazouz");
	// new->value = ft_strdup("mohamed");
	// new->next = NULL;
	// *env_lst = new;
	while (env[i])
	{
		new = lst_new(env[i]);
		ft_add_last(env_lst, new);
		i ++;
	}
	// printf("env_lst->name : %s\n", env_lst->name);
	// while (i < 2)
	// {
	// 	new = lst_new("mazouz=mohamed");
	// 	ft_add_last(&env_lst, new);
	// 	i ++;
	// }
}
