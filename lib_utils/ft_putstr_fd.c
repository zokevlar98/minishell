/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 04:05:07 by zqouri            #+#    #+#             */
/*   Updated: 2024/08/01 04:07:06 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_putstr_fd(char *str, int fd)
{
    int i;

    i = 0;
    if (!str)
        return ;
    while (str[i])
    {
        write(fd, &str[i], 1);
        i++;
    }
}
