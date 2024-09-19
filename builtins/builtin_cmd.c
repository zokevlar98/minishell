
#include "minishell.h"

void	ft_builtin(t_cmd *cmd_list, t_env **env_list)
{
	char	*cmd;
	
	cmd = lower_case(cmd_list->args[0]);
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
		ft_export(cmd_list, *env_list);
	else if (ft_strncmp(cmd, "exit", ft_strlen("exit")) == 0)
		ft_exit(cmd_list);
	else if (ft_strncmp(cmd, "unset", ft_strlen("unset")) == 0)
		ft_unset(cmd_list, env_list);
}
