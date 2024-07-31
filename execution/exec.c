/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 00:17:39 by zqouri            #+#    #+#             */
/*   Updated: 2024/07/31 05:13:41 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
    Builtins
    Executor "and or"
    pipes
    redirections
    Expanding
    
*/

int is_builtin(t_cmd *cmd_list)
{
    char *builtins[NUM_BUILTINS];
    int i;

    i = 0;
    builtins = {"echo", "cd", "pwd", "export", "unset", "env", "exit", NULL};
    while (builtins[i])
    {
        if (ft_strcmp(builtins[i], cmd_list->cmd) == 0)
            return (1);
        i++;
    }
    return (0);
}

void    ft_execut_cmd(t_cmd *cmd_list, t_env *env_list)
{
    if (is_builtin(cmd_list))
    {
        printf("we have builtin\n");
        // ft_execut_builtin(cmd_list, env_list);
    }
    // else
    //     ft_execut_cmd(cmd_list, env_list);

    // printf("%s\n", ft_env_search(env_list, "USER"));
}
