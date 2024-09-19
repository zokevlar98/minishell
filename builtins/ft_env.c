
#include "minishell.h"

void	ft_env(t_cmd *cmd, t_env *env)
{
	t_env	*tmp;
	
	tmp = env;
	if (cmd && !cmd->args[1])
	{
		while (tmp)
		{
			if (tmp->value && tmp->name)
				printf("%s=%s\n", tmp->name, tmp->value);
			else
				printf("%s=\n", tmp->name);
			tmp = tmp->next;
		}
	}
	else
	{
		ft_putstr_fd("env: '", STDOUT_FILENO);
		ft_putstr_fd(cmd->args[1], STDOUT_FILENO);
		ft_putstr_fd("': No such file or directory\n", STDOUT_FILENO);
	}
}
