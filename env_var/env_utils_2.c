	
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
