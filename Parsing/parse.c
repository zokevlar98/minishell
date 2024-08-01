/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 01:28:07 by mohmazou          #+#    #+#             */
/*   Updated: 2024/08/01 05:02:05 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"



t_cmd	*ft_parse_line(char *line)
{
	t_cmd	*cmd_list;
	char	**all_tokens;
	int		i;
	

	(void)all_tokens;
	
	cmd_list = NULL;
	i = 0;
	//check line
	if (ft_check_syntax(line) == 0)
	{
		printf("syntax error : %s\n", line);
		return (NULL);
	}
	//add extra space 
	line = ft_add_space(line, i);
	
	
	//tokenizing
	// all_tokens = tokenizing(line);
	//affich tokens
		// for (int i = 0; all_tokens[i]; i++)
		// {
		// 	printf("%s\n", all_tokens[i]);
		// }
	return ((t_cmd *)1);
}