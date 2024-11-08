/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 01:58:04 by zqouri            #+#    #+#             */
/*   Updated: 2024/11/08 09:53:56 by mohmazou         ###   ########.fr       */
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
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		if (res < 0 && sign == -1)
			if (str[i] - '0' > 8)
				return (-1);
		if (res < 0 && sign == 1)
			if (str[i] - '0' > 7)
				return (-1);
		i++;
	}
	if (res * sign == 9223372036854775807)
		return (255);
	return ((long long)(res * sign));
}

int	check_num(char *str)
{
	long long	x;

	x = ft_atoul(str);
	if (x == -1 && !is_ne_one(str))
		return (1);
	if (x > LLONG_MAX || x < LLONG_MIN)
		return (1);
	if (x == -1 && is_ne_one(str))
		exit_status (255);
	return (0);
}

int	ft_str_isdigit(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	if (!ft_isdigit(str[i]) && str[i + 1] == '\0')
		return (0);
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_exit(t_cmd *cmd)
{
	int		index;
	char	*str;

	index = max_index(cmd);
	str = ft_strtrim_(cmd->args[1]);
	if ((size_array(cmd->args) > 2 && ft_str_isdigit(str)))
	{
		ft_putstr_fd("exit\nminishell: exit: too many arguments\n", 2);
		return (1);
	}
	else if (!cmd->args[1])
		exit_status(0);
	else if (cmd->args[1] && ft_str_isdigit(str)
		&& !check_num(str))
		exit_status(ft_atoul(str));
	if (!index && cmd->pipe_line == 0)
		ft_putstr_fd("exit\n", STDERR_FILENO);
	if ((cmd->args[1] && !ft_str_isdigit(str))
		|| check_num(str))
		exit_error(cmd->args[1]);
	exit(exit_status(-1));
	return (exit_status(-1));
}
