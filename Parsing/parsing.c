
#include "../minishell.h"

int	cnt_split(char *line, char c, int in_word)
{
	int	count;
	int	s_q;
	int	d_q;
	int	i;

	count = 0;
	i = -1;
	s_q = 0;
	d_q = 0;
	while (line && line[++i])
	{
		if (line[i] == '\'' && !d_q)
			s_q = !s_q;
		if (line[i] == '\"' && !s_q)
			d_q = !d_q;
		if (line[i] != c && !in_word)
		{
			count++;
			in_word = 1;
		}
		if (line[i] == c && !s_q && !d_q)
			in_word = 0;
	}
	return (count);
}

void	sp_qt(char c, int *s_q, int *d_q)
{
	if (c == '\'' && !(*d_q))
		(*s_q) = !(*s_q);
	if (c == '\"' && !(*s_q))
		(*d_q) = !(*d_q);
}

t_utils	*utils_init(void)
{
	t_utils	*u;

	u = (t_utils *)ft_malloc(sizeof(t_utils), 0);
	u->i = -1;
	u->j = 0;
	u->k = 0;
	return (u);
}

char	**ft_split_cmd(char *line, char c, int s_q, int d_q)
{
	t_utils	*u;
	char	**cmd;

	u = utils_init();
	cmd = (char **)ft_malloc(sizeof(char *) * (cnt_split(line, c, 0) + 1), 0);
	while (line[++u->i])
	{
		sp_qt(line[u->i], &s_q, &d_q);
		if (line[u->i] != c)
		{
			if (u->k == -1)
				u->k = u->i;
		}
		if (line[u->i] == c && !s_q && !d_q && u->k != -1)
		{
			if (u->i > u->k)
				cmd[u->j++] = ft_substr(line, u->k, u->i - u->k);
			u->k = -1;
		}
	}
	if (u->k != -1 && u->i > u->k)
		cmd[u->j++] = ft_substr(line, u->k, u->i - u->k);
	cmd[u->j] = NULL;
	return (cmd);
}

void	ft_parsing(char *line, t_p_cmd **cp_list, t_env *env_list)
{
	char	**cmd;
	t_p_cmd	*cmd_list;
	t_p_cmd	*new_cmd;
	int		i;
	int sig_flag;

	cmd_list = NULL;
	i = 0;
	sig_flag = 0;
	cmd = ft_split_cmd(line, '|', 0, 0);
	while (cmd[i])
	{
		new_cmd = ft_new_cp(cmd[i], i, env_list);
		cp_add_back(&cmd_list, new_cmd);
		i++;
	}
	(*cp_list) = cmd_list;
	while(cmd_list && sig_flag != -1337)
	{
		herdoc_hundeler(&cmd_list, env_list, &sig_flag);
		cmd_list = cmd_list->next;
	}
	if (sig_flag == -1337 || sig_flag == -42)
	{
		(*cp_list) = NULL;
		if (sig_flag == -1337)
			exit_status(1);
		else
			exit_status(0);
	}
}
