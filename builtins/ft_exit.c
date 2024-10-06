/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 01:58:04 by zqouri            #+#    #+#             */
/*   Updated: 2024/10/06 17:08:59 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(t_cmd *cmd, int flag)
{
	ft_putstr_fd("exit\n", STDOUT_FILENO);
	if (cmd->args[1] != NULL)
		printf("minishell: exit: %s: numeric argument required\n", cmd->args[1]);
	exit(EXIT_SUCCESS);
	//check number of arguments
	//check if the argument is a number use ft_atoi with long long
	//check if we have pipe
	//exit_status
	// if (size_array(cmd->args) > 2)
	// {
	// 	if (flag)
	// 		ft_putstr("exit\n", STDOUT_FILENO);
	// 	ft_putstr_fd("minishell: exit: too many arguments\n", STDERR_FILENO);
	// }
}
