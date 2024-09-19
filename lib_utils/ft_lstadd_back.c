
#include "minishell.h"

void	ft_lstadd_back(t_cmd **lst, t_cmd *new)
{
	t_cmd *last;
	
	if (!lst || !new)
		return ;
	if (*lst)
	{
		last = ft_lstlast(*lst);
		if (!last)
			return ;
		last->next = new;
	}
	else
		(*lst) = new;
}

t_env	*ft_lstlast_env(t_env *env)
{
	if (!env)
		return (NULL);
	while (env->next)
		env = env->next;
	return (env);
}

void	ft_add_env_back(t_env **env, t_env *new)
{
	t_env	*last;
	t_env	*tmp;

	if (!env || !new)
		return ;
	if (*env)
	{
		last = ft_lstlast_env(*env);
		if (!last)
			return ;
		tmp = *env;
		tmp->next = new;
		new->prev = last;
	}
	else
		(*env) = new;
}
