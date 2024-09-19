
#include "minishell.h"

void	ft_exit(t_cmd *cmd)
{
	ft_putstr_fd("exit\n", STDOUT_FILENO);
	if (cmd->args[1] != NULL)
		printf("minishell: exit: %s: numeric argument required\n", cmd->args[1]);
	exit(EXIT_SUCCESS);
}
