	
#include "minishell.h"

char    **empty_env(void)
{
    char   **env;
    char    *str;

    str = getcwd(NULL, 0);
    env = (char **)ft_malloc(sizeof(char *) * 4, 0);
    env[0] = ft_strjoin("PWD=", str);
    env[1] = ft_strdup("SHLVL=0");
    env[2] = ft_strdup("_=/usr/bin/env");
    env[3] = NULL;
    return (env);
}

t_env	*ft_env_new_(char *key, char *value)
{
	t_env	*new;

	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->name = ft_strdup(key);
    new->value = ft_strdup(value);
	new->next = NULL;
	return (new);
}

t_env	*ft_env_new(char *env)
{
	t_env	*new;
	char	*equal;

	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	equal = ft_strchr(env, '=');
    if (!equal)
    {
        new->name = ft_strdup(env);
        new->value = NULL;
    }
    else
    {  
	    new->name = ft_substr(env, 0, equal - env);
	    new->value = ft_strdup(equal + 1);
    }
	new->next = NULL;
	return (new);
}

t_env   *find_env(t_env *env, char *name)
{
    t_env   *tmp;

    tmp = env;
    while (tmp)
    {
        if (ft_strncmp(tmp->name, name, ft_strlen(tmp->name)) == 0)
            return (tmp);
        tmp = tmp->next;
    }
    return (NULL);
}

int count_env(t_env *env)
{
    int     i;
    t_env   *tmp;

    i = 0;
    if (!env)
        return (0);
    tmp = env;
    while (tmp)
    {
        i++;
        tmp = tmp->next;
    }
    return (i);
}
