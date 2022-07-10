#include "client.h"

void	ft_send_sig_to_server(int signum, pid_t pid)
{
	int	count_bit;

	count_bit = 1;
	while (signum == SIGUSR2 && count_bit < 32)
	{
		kill(pid, SIGUSR1);
		printf("pong\n");
		count_bit++;
	}
	printf("count_bit = %d\n", count_bit);
}

int main(int argc, char **argv)
{
	struct sigaction sa;
	pid_t	pid;

	pid = atoi(argv[1]);
	kill(pid, SIGUSR1);
	sa.sa_sigaction = ft_send_sig_to_server;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR2, &sa, NULL);
	//ft_send_sig_to_server(SIGUSR1, pid);
	while(1)
		pause();
	return (0);
}
