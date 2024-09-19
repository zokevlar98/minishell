
#include "minishell.h"

void	ft_unset(t_cmd *cmd, t_env **env)
{
	t_env	*ptr;
	t_env	*tmp;
	t_env	*tmp1;

	ptr = *env;
	if (!cmd->args[1])
		return ;
	while (ptr && cmd->args[1])
	{
		if (ptr->name && !ft_strncmp(ptr->name, cmd->args[1], ft_strlen(ptr->name)))
		{
			free(ptr->name);
			free(ptr->value);
			if (ptr->next && ptr->prev){
				tmp1 = ptr->next;
				tmp = ptr->prev;
				tmp->next = tmp1;
				tmp1->prev = tmp;
			}
			else if (ptr->next && !ptr->prev){
				tmp = ptr->next;
				tmp->prev = NULL;
				free(ptr);
				*env = tmp;
				return;
			}
			else if (!ptr->next && ptr->prev){
				tmp = ptr->prev;
				tmp->next = NULL;
			}
			else
				*env = NULL;
			free(ptr);
			return ;				
		}
		ptr = ptr->next;
	}
}
