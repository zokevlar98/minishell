/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 04:09:21 by zqouri            #+#    #+#             */
/*   Updated: 2024/10/20 23:07:59 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

void    ft_error(char *str)
{
    //we can change this func to anther behiver
    perror(str);
    // exit(EXIT_FAILURE);
}

void    ft_execution_error(char *str)
{
    if (!str)
        return ;
    ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	exit(127);
}
