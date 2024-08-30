/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:11:11 by mohmazou          #+#    #+#             */
/*   Updated: 2024/08/30 16:15:36 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	close_fd(int *fd_list)
{
	int	i;

	i = 0;
	while (fd_list[i] && fd_list[i + 1])
	{
		close(fd_list[i]);
		i++;
	}
}

void	ft_add_fd(int *fd_list, int fd)
{
	int	i;

	i = 0;
	while (fd_list[i])
		i++;
	fd_list[i] = fd;
	fd_list[i + 1] = 0;
}

int	last_fd(int *fd_list)
{
	int	i;

	i = 0;
	while (fd_list[i])
		i++;
	return (fd_list[i - 1]);
}

void	open_in(char **in_redir, int *fd_in)
{
	int	fd;
	int	i;
	int	*fd_list;
	
	fd = 0;
	i = 0;
	fd_list = ft_malloc(100 * sizeof(int), 0);
	while (in_redir[i])
	{
		if (in_redir[i][0] == '<' && in_redir[i][1] == '<')
		{
			fd = open(in_redir[i]+2, O_RDWR | O_CREAT | O_APPEND, 0644);
			if (fd == -1)
				printf("Error: OPENING FILE\n");
			ft_add_fd(fd_list, fd);
		}
		else
		{
			if (in_redir[i][1] == '\"')
				fd = open(in_redir[i]+2, O_RDWR | O_CREAT | O_TRUNC, 0644);
			else
				fd = open(in_redir[i]+1, O_RDWR | O_CREAT | O_TRUNC, 0644);
			if (fd == -1)
				printf("Error: OPENING FILE\n");
			ft_add_fd(fd_list, fd);
		}
		i ++;
	}
	
	
	*fd_in = last_fd(fd_list);
	close_fd(fd_list);
}

void	open_out(char **out_redir, int *fd_out)
{
	int	fd;
	int	i;
	int	*fd_list;
	
	i = 0;
	fd_list = ft_malloc(100 * sizeof(int), 0);
	while (out_redir[i])
	{
		if (out_redir[i][0] == '>' && out_redir[i][1] == '>')
		{
			fd = open(out_redir[i]+2, O_RDWR | O_CREAT | O_APPEND, 0644);
			if (fd == -1)
				printf("Error: OPENING FILE\n");
			ft_add_fd(fd_list, fd);
		}
		else
		{
			if (out_redir[i][1] == '\"')
				fd = open(out_redir[i]+2, O_RDWR | O_CREAT | O_TRUNC, 0644);
			else
				fd = open(out_redir[i]+1, O_RDWR | O_CREAT | O_TRUNC, 0644);
			if (fd == -1)
				printf("Error: OPENING FILE\n");
			ft_add_fd(fd_list, fd);
		}
		i ++;
	}
	*fd_out = last_fd(fd_list);
}

void	open_file(t_p_cmd *cmd_p_lit, t_cmd *cmd_list)
{
	t_cmd	*tmp;
	t_p_cmd	*tmp_p;

	tmp = cmd_list;
	tmp_p = cmd_p_lit;

	while (tmp_p)
	{
		if (tmp_p->in_redir)
			open_in(tmp_p->in_redir, &tmp->fd_in);
		if (tmp_p->out_redir)
			open_out(tmp_p->out_redir, &tmp->fd_out);

		tmp_p = tmp_p->next;
		tmp = tmp->next;
	}
}
