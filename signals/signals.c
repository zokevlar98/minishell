
#include "../minishell.h"



void	int_handel(int sig)
{
	printf("handle signals\n");
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	exit_status(1);
}

void ft_sig_herdoc(int sig)
{
	(void)sig;
	close(0);
	write(1, "\n", 1);
	exit_status(-1337);
}
void	ft_handle_signals(void)
{
	signal(SIGINT, int_handel);
	signal(SIGQUIT, SIG_IGN);
}