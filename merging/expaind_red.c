
#include "minishell.h"

char	*expd_rd(char *f_name, t_env *env, int pipe_line)
{
	char	*new_name;

	new_name = expd_line(f_name, env, pipe_line);
	if (cnt_split(new_name, ' ', 0) != 1)
	{
		printf("minishell: %s: ambiguous redirect\n", new_name);
		return (NULL);
	}
	return (new_name);
}

char	*get_f_name(char *f_name, t_env *env, int pipe_line)
{
	char	*new_name;

	new_name = f_name;
	if (to_expand(new_name))
		new_name = expd_rd(new_name, env, pipe_line);
	if (!new_name)
		return (NULL);
	// if (ft_strcmp(f_name, "\"\"") == 0)
	// {
	// 	printf("minishell: %s: No such file or directory\n", f_name);
	// 	return (NULL);
	// }
	if (!ft_strcmp(rm_qot(new_name, 0, 0), "\0"))
	{
		printf("minishell: %s: No such file or directory\n",
			rm_qot(new_name, 0, 0));
		return (NULL);
	}
	return (rm_qot(new_name, 0, 0));
}
