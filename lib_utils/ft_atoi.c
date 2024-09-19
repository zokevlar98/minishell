
#include "minishell.h"

int	ft_signe(int signe)
{
	if (signe > 0)
		return (-1);
	return (0);
}

int ft_atoi(char *str)
{
	int			i;
	int			signe;
	long long	resu;

	i = 0;
	signe = 1;
	resu = 0;
    if (!str)
	{
        return (0);
	}
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = -signe;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (resu > 922337203685477580 
			|| (resu == 922337203685477580 && str[i] > 7))
			return (ft_signe(signe));
		resu = 10 * resu + str[i] - '0';
		i++;
	}
	return (resu * signe);
}
