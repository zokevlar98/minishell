/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 06:24:23 by mohmazou          #+#    #+#             */
/*   Updated: 2024/10/07 07:17:46 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	herdoc_hundeler(char *del, t_env *env)
{
	int		fd;
	char	*line;
	char	*new_path;
	char	*buffer;
	static int	i;
(void)env;
	buffer = NULL;
	new_path = ft_strjoin("/tmp/mohmazou/herdoc", ft_itoa(i++));
	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (ft_strcmp(line, del) == 0)
		{
			free(line);
			break ;
		}
		buffer = ft_strjoin(buffer, line);
		buffer = ft_strjoin(buffer, "\n");
		free(line);
	}
	fd = open(new_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		ft_error("open failed");
	write(fd, buffer, ft_strlen(buffer));
	close(fd);
	fd = open(new_path, O_RDONLY);
	if (fd == -1)
		ft_error("open failed");
	return (fd);
}
