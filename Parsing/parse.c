/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 01:28:07 by mohmazou          #+#    #+#             */
/*   Updated: 2024/08/02 04:20:06 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"



t_cmd	*ft_parse_line(char *line)
{
	t_cmd	*cmd_list;
	char	**all_tokens;
	int		i;
	char	*new_line;
	

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
	new_line = ft_add_space(line, i);
	
	
	//tokenizing
	all_tokens = tokenizing(new_line);
	if (!ft_check_tokens(all_tokens))
	{
		printf("syntax error : %s\n", line);
		return (NULL);
	}
	//affich tokens
		// for (int i = 0; all_tokens[i]; i++)
		// {
		// 	printf("token[%d] --%s--\n",i , all_tokens[i]);
		// }
	
	return ((t_cmd *)1);
}