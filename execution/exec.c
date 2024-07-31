/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 00:17:39 by zqouri            #+#    #+#             */
/*   Updated: 2024/07/31 00:21:22 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec(t_cmd *cmd, t_env *env_list)
{
    pid_t	pid;
    int		status;

    pid = fork();
    if (pid == 0)
    {
        if (execve(cmd->cmd, cmd->args, NULL) == -1)
        {
            printf("minishell: %s: %s\n", cmd->cmd, strerror(errno));
            exit(1);
        }
    }
    else if (pid < 0)
    {
        printf("minishell: %s\n", strerror(errno));
        exit(1);
    }
    else
    {
        waitpid(pid, &status, 0);
    }
}
