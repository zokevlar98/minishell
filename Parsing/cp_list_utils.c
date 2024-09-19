
#include "minishell.h"

t_p_cmd	*ft_new_cp(char *cmd, int i, t_env *env_list)
{
	t_p_cmd	*new_cmd;

	// new_cmd = ft_malloc(sizeof(t_p_cmd), 0);
	new_cmd = (t_p_cmd *)malloc(sizeof(t_p_cmd));
	if (!new_cmd)
		return (NULL);
	new_cmd->pipe_line = i;
	get_line(cmd, new_cmd, env_list);
	new_cmd->next = NULL;
	return (new_cmd);
}

void	cp_add_back(t_p_cmd **cp_list, t_p_cmd *new_cmd)
{
	t_p_cmd	*tmp;

	if (!(*cp_list))
	{
		(*cp_list) = new_cmd;
		return ;
	}
	tmp = (*cp_list);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_cmd;
}
