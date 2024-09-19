
#include "minishell.h"

void	ft_change_env(t_env *env_list, char *name, char *value)
{
	t_env	*tmp;

	tmp = env_list;
	while (tmp)
	{
		if (ft_strncmp(tmp->name, name, ft_strlen(tmp->name)) == 0)
		{
			// free(tmp->value);// if this line is uncommented, the program  will double free becouse of ft_malloc i need a solution
			tmp->value = ft_strdup(value);
			return ;
		}
		tmp = tmp->next;
	}
	if (!tmp)
	{
		tmp = ft_env_new_(name, value);
		ft_env_add_back(&env_list, tmp);
	}
	free(value);
}

char	*ft_env_search(t_env *env_list, char *name)
{
	t_env	*tmp;

	tmp = env_list;
	while (tmp)
	{
		if (!ft_strncmp(tmp->name, name, ft_strlen(tmp->name)))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

t_env	*ft_env_new_(char *key, char *value)
{
	t_env	*new;

	new = (t_env *)ft_malloc(sizeof(t_env), 0);
	if (!new)
		return (NULL);
	new->name = ft_strdup(key);
	new->value = ft_strdup(value);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}


t_env	*ft_env_new(char *env)
{
	t_env	*new;
	char	*equal;

	new = (t_env *)ft_malloc(sizeof(t_env), 0);
	if (!new)
		return (NULL);
	equal = ft_strchr(env, '=');
	new->name = ft_substr(env, 0, equal - env);
	new->value = ft_strdup(equal + 1);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_env_add_back(t_env **env_list, t_env *new)
{
	t_env	*tmp;

	if (!*env_list)
	{
		*env_list = new;
		return ;
	}
	tmp = *env_list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

void	ft_env_list(t_env **env_list, char **env)
{
	int		i;
	t_env	*new;

	i = 0;
	new = NULL;
	while (env[i])
	{
		new = ft_env_new(env[i]);
		ft_env_add_back(env_list, new);
		i++;
	}
}
