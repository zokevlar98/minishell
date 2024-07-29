/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 23:03:57 by mohmazou          #+#    #+#             */
/*   Updated: 2024/07/29 01:29:05 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char    *get_env_value(t_env *env_lst, char *name)
{
    t_env	*tmp;

    tmp = env_lst;
    while (tmp)
    {
        if (!ft_strcmp(tmp->name, name))
            return (tmp->value);
        tmp = tmp->next;
    }
    return (NULL);
}