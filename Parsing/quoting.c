/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quoting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 02:15:19 by mohmazou          #+#    #+#             */
/*   Updated: 2024/09/01 02:22:56 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/minishell.h"

void remove_quotes(char *str)
{
    int i = 0, j = 0;

    while (str[i])
	{
        if (str[i] != '"' && str[i] != '\'')
		{
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';
}

void	ft_quoting(t_cmd *cmd_list)
{
	t_cmd	*tmp;
	int		i;

	tmp = cmd_list;
	while (tmp)
	{
		if (tmp->args)
		{
			i = 0;
			while (tmp->args[i])
			{
				remove_quotes(tmp->args[i]);
				i++;
			}
		}
		tmp = tmp->next;
	}
}