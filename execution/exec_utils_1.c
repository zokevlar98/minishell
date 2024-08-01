/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 04:45:05 by zqouri            #+#    #+#             */
/*   Updated: 2024/08/01 04:47:53 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

// int ft_check_env(t_cmd *cmd_list)
// {
//     int     i;
//     char    *cmd;

//     i = 0;
//     cmd = cmd_list->cmd;
//     while (cmd[i] == '\t' || cmd[i] == ' ' || cmd[i] == '\n')
//         i++;
//     while (cmd[i])
//     {
//         if (cmd[i] == '$')
//             return (1);
//         i++;
//     }
//     return (0);
// }
