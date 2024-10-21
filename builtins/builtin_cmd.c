/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 03:56:00 by zqouri            #+#    #+#             */
/*   Updated: 2024/10/21 03:32:23 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_builtin(t_cmd *cmd_list, t_env **env_list)
{
	char	*cmd;
	
	cmd = cmd_list->args[0];
	if (!cmd || cmd_list->fd_in == -1 || cmd_list->fd_out == -1)
		return ;
	dup2(cmd_list->fd_in , STDIN_FILENO);
	dup2(cmd_list->fd_out , STDOUT_FILENO);
	if (ft_strncmp(cmd, "echo", ft_strlen("echo")) == 0)
		ft_echo(cmd_list);
	else if (ft_strncmp(cmd, "cd", ft_strlen("cd")) == 0)
		ft_cd(cmd_list, *env_list);
	else if (ft_strncmp(cmd, "pwd", ft_strlen("pwd")) == 0)
		ft_pwd(*env_list);
	else if (ft_strncmp(cmd, "env", ft_strlen("env")) == 0)
		ft_env(cmd_list, *env_list);
	else if (ft_strncmp(cmd, "export", ft_strlen("export")) == 0)
		ft_export(cmd_list, env_list);
	else if (ft_strncmp(cmd, "exit", ft_strlen("exit")) == 0)
		ft_exit(cmd_list, 1);
	else if (ft_strncmp(cmd, "unset", ft_strlen("unset")) == 0)
		ft_unset(cmd_list, env_list);
}

void	ft_export_error(char *name)
{
	ft_putstr_fd("minishell: export: `", STDERR_FILENO);
	ft_putstr_fd(name, STDERR_FILENO);
	ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
}

void	print_list_declare(t_env **env)
{
	t_env	*current_env;
	t_env	*tmp;
	char	**envp;

	current_env = NULL;
	tmp = *env;
	envp = sort_env(tmp, count_env(tmp));
	ft_env_list(&current_env, envp, 1);
	ft_free(envp);
	while (current_env)
	{
		if (ft_strcmp(current_env->name, "_") == 0)
		{
			current_env = current_env->next;
			continue ;
		}
		if (current_env->name && current_env->value)
			printf("declare -x %s=\"%s\"\n", current_env->name, current_env->value);
		else if (!current_env->value)
			printf("declare -x %s\n", current_env->name);
		current_env = current_env->next;
	}
	//free env linkedlist
}

char	*check_name_env(char *name)
{
	int	i;

	i = 0;
	while (name[i])
	{
		if (name[i] == '+')
			return (ft_substr(name, 0, i));
		i++;
	}
	return (name);
}

int	check_empty_value(char *var)
{
	int	i;

	i = 0;
	while (var[i])
	{
		if (var[i] == '=' && var[i + 1] == '\0')
			return (0);
		i++;
	}
	return (1);
}
