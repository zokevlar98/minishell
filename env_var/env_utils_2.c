/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 06:28:16 by zqouri            #+#    #+#             */
/*   Updated: 2024/08/28 07:34:15 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    **empty_env(void)
{
    char   **env;
    char    *str;

    str = getcwd(NULL, 0);
    env = (char **)malloc(sizeof(char *) * 4);
    if (!env)
        ft_error("malloc failed\n");
    env[0] = ft_strjoin("PWD=", str);
    env[1] = ft_strdup("SHLVL=1");
    env[2] = ft_strdup("_=/usr/bin/env");
    env[3] = NULL;
    return (env);
}

int size_array(char **arry)
{
    int i;

    i = 0;
    if (!arry)
        return (0);
    while (arry[i] != NULL)
        i++;
    return (i);
}
