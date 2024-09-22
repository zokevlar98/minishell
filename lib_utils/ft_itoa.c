/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 01:18:13 by zqouri            #+#    #+#             */
/*   Updated: 2024/09/21 03:43:40 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_count_number(int n)
{
	size_t	len;

	len = 0;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_zero(void)
{
	char	*str;

	str = ft_strdup("0");
	return (str);
}

size_t	ft_check_is_negative(int *n, size_t count)
{
	count = 0;
	if (*n < 0)
	{
		*n = *n * -1;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	size_t		i;
	size_t		count;
	char		*nbr;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_zero());
	i = 0;
	count = 0;
	count = ft_check_is_negative(&n, count) + ft_count_number(n);
	nbr = (char *)malloc(sizeof(char) * (count + 1));
	if (!nbr)
		return (NULL);
	if ((n * (-1)) < 0)
		nbr[0] = '-';
	while (n > 0)
	{
		nbr[count - i - 1] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	nbr[count] = '\0';
	return (nbr);
}
