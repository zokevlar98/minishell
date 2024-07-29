/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:02:40 by mohmazou          #+#    #+#             */
/*   Updated: 2024/07/29 03:38:54 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdio.h>
void	ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(2);
}

void	free_env(char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		free(env[i]);
		i++;
	}
	free(env);
}

void at_exit(void)
{
	system("leaks minishell");
}


void free_env_lst(t_env *env_lst)
{
	t_env	*tmp;

	env_lst = env_lst->next;
	while (env_lst)
	{
		tmp = env_lst;
		env_lst = env_lst->next;
		free(tmp->name);
		free(tmp->value);
		free(tmp);
	}
	free(env_lst);
}

int main(int argc, char **argv, char **env)
{
	char	*line;
	t_env	*env_lst;
	t_cmd	*cmd;
	
	if (argc != 1 || argv[1])
		ft_error("Error: too many arguments\n");
	env_lst = NULL;
	cmd = NULL;
	 
	ft_envlst(env, &env_lst);
	// Start the minishell
	while (1)
	{
		// Read the command
		line = readline("minishell$ > ");
		if (!line)
			ft_error("Error: readline faild\n");
		if (!ft_strcmp(line, "exit") && *line != '\0')
		{
			free(line);
			break;
		}
		add_history(line);
		if (!checking_line(line))
		{
			printf("Error: syntax error\n");
			continue;
		}
		ft_minishell(line, env_lst, &cmd);
		while (cmd)
		{
			printf("\ncmd->ful_cmd : %s\n", cmd->ful_cmd);
			printf("cmd->pipe_line : %d\n", cmd->pipe_line);
			printf("cmd->cmd : %s\n", cmd->cmd);
			// printf("cmd->args : %s\n", cmd->args);
			printf("cmd->in_redir : %s\n", cmd->in_redir);
			printf("cmd->out_redir : %s\n\n", cmd->out_redir);
			cmd = cmd->next;
		}
		cmd = NULL;
		free(line);
	}
	
	
	// Free the env_par variable
	// free_env(env_par);
	// free_env_lst(env_lst);
	return (0);
}