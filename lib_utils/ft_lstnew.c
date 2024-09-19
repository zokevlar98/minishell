
#include "minishell.h"

t_cmd	*ft_lstnew_cmd(char *cmd)
{
	t_cmd	*new;
	char	**args;

	new = (t_cmd *)ft_malloc(sizeof(t_cmd), 0);
	// new->ful_cmd = ft_strdup(cmd);
	args = ft_split(cmd, ' ');
	// new->cmd = ft_strdup(args[0]);
	new->args = args;
	new->fd_in = 0;
	new->fd_out = 1;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back_cmd(t_cmd **cmd_list, t_cmd *new)
{
	t_cmd	*last;

	if (!cmd_list || !new)
		return ;
	if (*cmd_list)
	{
		last = ft_lstlast(*cmd_list);
		if (!last)
			return ;
		last->next = new;
	}
	else
		(*cmd_list) = new;
}
