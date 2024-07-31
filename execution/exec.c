/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 00:17:39 by zqouri            #+#    #+#             */
/*   Updated: 2024/07/31 07:00:11 by zqouri           ###   ########.fr       */
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
    char    *builtins[NUM_BUILTINS];
    int     i;
    char    *cmd;

    i = 0;
    cmd = lower_case(cmd_list->cmd);
    
    builtins[0] = "echo";
    builtins[1] = "cd";
    builtins[2] = "pwd";
    builtins[3] = "export";
    builtins[4] = "unset";
    builtins[5] = "env";
    builtins[6] = "exit";
    builtins[7] = NULL;
    while (builtins[i])
    {
        if (ft_strncmp(builtins[i], cmd, ft_strlen(builtins[i])) == 0)
            return (1);
        i++;
    }
    return (0);
}

int ft_check_env(t_cmd *cmd_list)
{
    int     i;
    char    *cmd;

    i = 0;
    cmd = cmd_list->cmd;
    while (cmd[i] == '\t' || cmd[i] == ' ' || cmd[i] == '\n')
        i++;
    while (cmd[i])
    {
        if (cmd[i] == '$')
            return (1);
        i++;
    }
}

// void    ft_execut_builtin(t_cmd *cmd_list, t_env *env_list)
// {
//     //execute builtin
// }

// void    ft_execut_cmd(t_cmd *cmd_list, t_env *env_list)
// {
//     //execute command
// }

void    ft_execut_cmd(t_cmd *cmd_list, t_env *env_list)
{
    (void)env_list;
    //if we have env
    if (ft_check_env(cmd_list))
    {
         printf("we have env\n");
        // ft_check_env(cmd_list);
    }
    if (is_builtin(cmd_list))
    {
        // printf("we have builtin\n");
        // ft_execut_builtin(cmd_list, env_list);
    }
    // else
    //     ft_execut_cmd(cmd_list, env_list);

    // printf("%s\n", ft_env_search(env_list, "USER"));
}
