/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:38:28 by zqouri            #+#    #+#             */
/*   Updated: 2024/09/17 19:33:53 by zqouri           ###   ########.fr       */

/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export_error(t_cmd *cmd)
{
	t_cmd	*tmp;
	int		i;

	i = 2;
	tmp = cmd;
	//this error handling need more work
	while (tmp->args[i])
	{
		ft_putstr_fd("minishell: export: `", STDERR_FILENO);
		ft_putstr_fd(tmp->args[i], STDERR_FILENO);
		ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
		i++;	
	}
}

void	affiche_sort_env(t_env *env)
{
	int		i;
	int		j;
	char	**envp;

	i = 0;
	envp = ft_get_envp(env);
	while (envp[i])
	{
		j = i + 1;
		while (envp[j])
		{
			if (ft_strncmp(envp[i], envp[j], ft_strlen(envp[i])) > 0)
			{
				envp[i] = envp[j];
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (envp[i])
	{
		printf("declare -x %s\n", envp[i]);
		i++;
	}
}

void	print_list_declare(t_env *env)
{
	while (env)
	{
		// I need to print with alhabetical order
		printf("declare -x %s=\"%s\"\n", env->name, env->value);
		env = env->next;
	}
}

void	ft_export(t_cmd *cmd, t_env *env)
{
	t_env	*tmp;
	t_env	*p;
	t_env	*new;
	char	**str;
//export is not working correctly if more than tow env variable are passed the 1st
//one is being exported and the ather one is not being exported

/*bash-3.2$ export 1a1=""
bash: export: `1a1=': not a valid identifier
bash-3.2$ export _a1=""
*/
	tmp = env;
	p = env;
	if (!cmd->args[1])
	{
		print_list_declare(tmp);
		// affiche_sort_env(tmp);
		return ;
	}
	while (tmp)
	{
		if (ft_strncmp(tmp->name, cmd->args[1], ft_strlen(tmp->name)) == 0)
		{
			str = ft_split(cmd->args[1], '=');
			ft_change_env(p, tmp->name, str[1]);
			return ;
		}
		tmp = tmp->next;
	}
	if (ft_strchr(cmd->args[1], '='))
	{
		//hendling the case export var======5 & export 1a1="hello" export _a1=""
		//Also export -var=42 or export +var=42
		str = ft_split(cmd->args[1], '=');
		new = ft_env_new_(str[0], str[1]);
		if (!new)
			ft_error("error: feailed");
		ft_env_add_back(&env, new);
		return ;
	}
	ft_export_error(cmd);
}
