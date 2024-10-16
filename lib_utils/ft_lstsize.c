
#include "minishell.h"

int	ft_lstsize(t_cmd *lst)
{
	int 	i;
	t_cmd	*tmp;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);	
}
