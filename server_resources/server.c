#include "../ft_printf/ft_printf.h"
#include <signal.h>
#include <limits.h>

char *str = NULL;

void    ft_putchar_fd(char a, int fd)
{
	write(fd, &a, 1);
}

void	ft_binary_becomes_char(int signum, int bit, siginfo_t *info)
{
	static int	a = 0;

	if (bit < 8)
	{
		a = a << 1;
		if (signum == SIGUSR1)
			a = a + 1;
		if (signum == SIGUSR2)
			a = a + 0;
	}
	if (bit == 7)
	{
		ft_putchar_fd(a, 1);
		a = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

void	ft_signals_handler(int signum, siginfo_t *info, void *name)
{
	static int	count_bit = 0;
	(void)name;

	ft_binary_becomes_char(signum, (count_bit % 8), info);
	count_bit++;
}

int main(void)
{
	struct sigaction sa;

	printf("server's pid: %d\n", getpid());
	sa.sa_sigaction = ft_signals_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while(1)
		pause();
	return (0);
}
