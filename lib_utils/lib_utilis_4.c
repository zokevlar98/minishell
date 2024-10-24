/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utilis_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:03:24 by zqouri            #+#    #+#             */
/*   Updated: 2024/10/25 00:18:30 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	size_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return (0);
	while (array[i] != NULL)
		i++;
	return (i);
}

void	close_fd(int fd_in, int fd_out)
{
	if (fd_in != 0)
		close(fd_in);
	if (fd_out != 1)
		close(fd_out);
}
