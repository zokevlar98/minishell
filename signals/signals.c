
#include "minishell.h"

void	int_handel(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_redisplay();
	exit_status(1);
}

void	quit_handel(int sig)
{
	(void)sig;
	return ;
}

void	ft_handle_signals(void)
{
	signal(SIGINT, int_handel);
	signal(SIGQUIT, quit_handel);
}