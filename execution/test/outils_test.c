
#include "minishell.h"

void	affiche_env(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	if (tmp)
	{
		while (tmp)
		{
			printf("%s=%s\n", tmp->name, tmp->value);
			tmp = tmp->next;
		}
	}	
}

void	ff(void)
{
	system("leaks minishell");	
}
