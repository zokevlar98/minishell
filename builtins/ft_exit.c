/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri < zqouri@student.1337.ma >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 01:58:04 by zqouri            #+#    #+#             */
/*   Updated: 2024/08/13 18:38:40 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(t_cmd *cmd)
{
	ft_putstr_fd("exit\n", 1);
	if (cmd->args[1] != NULL)
		printf("minishell: exit: %s: numeric argument required\n", cmd->args[1]);
	exit(EXIT_SUCCESS);
}
