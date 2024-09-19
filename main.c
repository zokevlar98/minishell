
#include "minishell.h"

int	ft_add(char *line)
{
	if (!line)
	{
		printf("exit\n");
		ft_malloc(0, 1);
		exit(0);
	}
	if (line[0] == '\0' || all_space(line))
		return (1);
	if (!ft_check_syntax(line))
	{
		printf("syntax error\n");
		add_history(line);
		return (1);
	}
	add_history(line);
	return (0);
}

void	start_loop(t_env *env_list)
{
	char	*line;
	t_p_cmd	*cp_list;
	t_cmd	*cmd_list;

	shell_lvl(env_list);
	while (1)
	{
		line = readline("minishell$>  ");
		if (ft_add(line))
		{
			free(line);
			continue ;
		}
		if (ft_strcmp(line, "exit") == 0)
		{
			free(line);
			break ;
		}
		ft_parsing(line, &cp_list, env_list);
		cmd_list = NULL;
		ft_merge(&cmd_list, cp_list, env_list);
		ft_execut_cmd(cmd_list, &env_list);
		free(line);
	}
}

int	main(int ac, char **av, char **env)
{
	t_env	*env_list;

	if (ac != 1 || av[1])
		return (write(2, "Error: no arguments needed\n", 27));
	if (!env[0])
		env = empty_env();
	env_list = NULL;
	ft_env_list(&env_list, env);
	// ft_handle_signals();
	start_loop(env_list);
	ft_malloc(0, 1);
	
	return (0);
}
