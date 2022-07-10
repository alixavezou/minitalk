#include "../ft_printf/ft_printf.h"
#include <signal.h>
#include <limits.h>

void	ft_send_sig_to_client(int signum, siginfo_t *info, void *name)
{
	static int	count_sig;

	count_sig = 0;
	while (signum == SIGUSR1 && count_sig < 32)
	{
		kill(info->si_pid, SIGUSR2);
		printf("ping\n");
		count_sig++;
	}
	printf("count_sig = %d\n", count_sig);
}

int main(void)
{
	struct sigaction sa;
	printf("server's pid: %d\n", getpid());
	sa.sa_sigaction = ft_send_sig_to_client;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
