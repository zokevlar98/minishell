
#include "../minishell.h"

int	should_expd(char *buffer)
{
	while (*buffer)
	{
		if (*buffer == '$')
		{
			buffer ++;
			if (*buffer != '$' && *buffer != '\'' && *buffer != '\"' && *buffer != ' ')
				return (1);
		}
		buffer ++;
	}
	return (0);
}

int	fill_buffer(t_env *env, char *bfr,char *new_bf,int pipe_line)
{
	int	i = 0;
	int	j = 0;
	int len = ft_strlen(bfr);
	int	status;

	while (i < len)
	{
		status = (bfr[i] == '$' && bfr[i + 1]);
		if (status && bfr[i + 1] != ' ' && bfr[i +1] != '\t')
			i++;
		if (status && bfr[i] == '?')
			join_exit(new_bf, pipe_line, &j, &i);
		else if (status && not_expandable(bfr[i]))
			i ++;
		else if (status && ft_to_ex(bfr[i]))
		{
			join_val(env, bfr + i, new_bf, &j);
			while (bfr[i] && ft_to_ex(bfr[i]))
				i ++;
		}
		else
			new_bf[j++] = bfr[i++];
	}
	return 0;
}

char	*expended_buffer(char *buffer, t_env *env, int pipe_line)
{
	char	*new_bf;
	int		len;

	if (!buffer || !should_expd(buffer))
		return (buffer);
	len = new_len(buffer,env);
	new_bf = allocat_zero(len + 1);
	if (fill_buffer(env, buffer, new_bf, pipe_line) == -1)
		return (NULL);
	return (new_bf);

	

}