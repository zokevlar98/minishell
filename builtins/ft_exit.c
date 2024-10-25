/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 01:58:04 by zqouri            #+#    #+#             */
/*   Updated: 2024/10/25 19:24:33 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exit_error(char *str)
{
	ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
	exit_status(255);
}

long long	ft_atoul(const char *str)
{
	long long	res;
	int			i;
	int			sign;

	res = 0;
	i = 0;
	sign = 1;
	if (!str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{//ovverflow
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

int	ft_str_isdigit(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	if (ft_atoul(str) > 9223372036854775807)
		return (0);
	return (1);
}

int max_index(t_cmd *cmd)
{
	while (cmd->next)
		cmd = cmd->next;
	return (cmd->pipe_line);
}

void	ft_exit(t_cmd *cmd)
{
	int 		index;
	//if numbers to big message error and exit 255!
	index = max_index(cmd);
	if (size_array(cmd->args) > 2 && ft_str_isdigit(cmd->args[1]))
	{
		ft_putstr_fd("exit\n", STDERR_FILENO);
		ft_putstr_fd("minishell: exit: too many arguments\n", STDERR_FILENO);
		exit_status(1);
		return ;
	}
	else if (!cmd->args[1])
		exit_status(0);
	else if (cmd->args[1] && ft_str_isdigit(cmd->args[1]))
		exit_status(ft_atoul(cmd->args[1]));
	if (!index)
		ft_putstr_fd("exit\n", STDERR_FILENO);
	if (cmd->args[1] && !ft_str_isdigit(cmd->args[1]))
		exit_error(cmd->args[1]);
	if (!index)
		exit(exit_status(-1));
}
