/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 00:17:39 by zqouri            #+#    #+#             */
/*   Updated: 2024/08/01 04:50:08 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
    Builtins
    Executor "and or"
    pipes
    redirections
    Expanding

    first we serch for a pipe line
    then we search for redirections
    then we search for builtins
    then we search for commands 
*/

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
    // if (ft_check_env(cmd_list))
    // {
    //      printf("we have env\n");
    //     // ft_check_env(cmd_list);
    // }
    if (is_builtin(cmd_list))
    {
        // printf("we have builtin\n");
        // ft_execut_builtin(cmd_list, env_list);
    }
    // else
    //     ft_execut_cmd(cmd_list, env_list);

    // printf("%s\n", ft_env_search(env_list, "USER"));
}
