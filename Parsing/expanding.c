/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanding.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:13:44 by mohmazou          #+#    #+#             */
/*   Updated: 2024/08/10 09:07:44 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// char	*expand_env(char *token_i)
// {
// 	char	*token;
// 	char	*env;
// 	char	*value;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	token = ft_strdup(token_i);
// 	while (token[i])
// 	{
// 		if (token[i] == '$')
// 		{
// 			i++;
// 			if (token[i] == '?')
// 			{
// 				value = ft_itoa(g_exit_status);
// 				env = ft_strjoin(token, value);
// 				free(value);
// 				free(token);
// 				return (env);
// 			}
// 			while (token[i] && ft_isalnum(token[i]))
// 				i++;
// 			env = ft_substr(token, j, i - j);
// 			value = get_env_value(env);
// 			free(env);
// 			env = ft_strjoin(token, value);
// 			free(value);
// 			free(token);
// 			token = env;
// 		}
// 		i++;
// 	}
// 	return (token);
// }

int	ft_isalnum(char c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

char	*ft_get_name(char *token_i, int *i)
{
	char	*name;
	int		j;
	int		k;

	j = *i;
	k = *i;
	while (token_i[k] && ft_isalnum(token_i[k]))
		k ++;
	*i = k;
	name = ft_substr(token_i, j, k - j);
	return (name);
}

char	*ft_add_char(char *str, char c)
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = ft_malloc(sizeof(char) * (ft_strlen(str) + 2), 0);
	if (!new_str)
		return (NULL);
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = c;
	new_str[i + 1] = '\0';
	return (new_str);
}

char	*expand_env(char *token_i, t_env *env_list)
{
	char	*name;
	int		i;
	char	*new_token;
	// int		s_quote;
	// int		d_quote;
	
	new_token = ft_malloc(sizeof(char) * 1000, 0);
	i = 0;

	while (token_i[i])
	{
		if (token_i[i] == '$')
		{
			i ++;
			name = ft_get_name(token_i, &i);
			// if (token_i[i] == '?')
			// {
			// 	value = ft_itoa(g_exit_status);
			// 	env = ft_strjoin(token, value);
			// 	free(value);
			// 	free(token);
			// 	return (env);
			// }
			// printf("token: %s\n", );
			new_token = ft_strjoin(new_token, ft_env_search(env_list, name));
		}
		else
		{
			new_token = ft_add_char(new_token, token_i[i]);
			i ++;
		}
	}
	return (new_token);
}

char	**expand_tokens(char **tokens, t_env *env_list)
{
	char	**new_tokens;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_tokens = ft_malloc(sizeof(char *) * MAX_TOKENS, 0);
	if (!new_tokens)
		return (NULL);
	while (tokens[i])
	{
		if (ft_strchr(tokens[i], '$'))
			new_tokens[j ++] = expand_env(tokens[i], env_list);
		else
			new_tokens[j ++] = ft_strdup(tokens[i]);
		i ++;
	}
	
return (new_tokens);
}