/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utilis_exec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 05:40:40 by zqouri            #+#    #+#             */
/*   Updated: 2024/10/21 14:28:19 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// char    *lower_case(char *str) // ila ma5damtch biha nemsse7ha
// {
//     int i;

//     i = 0;
// 	if (!str)
// 		return (NULL);
//     while (str[i])
//     {
//         if (str[i] >= 'A' && str[i] <= 'Z')
//             str[i] += 32;
//         i++;
//     }
//     return (str);
// }

int ft_strncmp(char *s1, char *s2, size_t size)
{
    size_t  i;

    i = 0;
    if (!s1 || !s2)
        return (0);
    while (i < size - 1 && s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
