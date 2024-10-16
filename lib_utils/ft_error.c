
#include "minishell.h"

void    ft_error(char *str)
{
    //we can change this func to anther behiver
    perror(str);
    // exit(EXIT_FAILURE);
}
