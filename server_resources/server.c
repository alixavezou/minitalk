#include "../ft_printf/ft_printf.h"
#include <signal.h>
#include <limits.h>

char *str = NULL;

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_len_to_int(int signum, int i)
{
	static int	len = 0;

	if (i < 32)
	{
		len = len << 1;
		if (signum == SIGUSR1)
		{
			len = len + 1;
		}
		if (signum == SIGUSR2)
		{
			len = len + 0;
		}
	}
	if (i == 31)
	{
		// printf("la taille de la str = %d\n", len);
		str = malloc(sizeof(char) * (len + 1));
		if (!str)
			return ;
		len = 0;
	}
}

void	ft_binary_becomes_char(int signum, int index, int bit, int *i)
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
		if (str)
		{
			// printf("je rentre index= %d\n", index);
			str[index] = a;
			if (a == '\0')
			{
				ft_putstr_fd(str, 1);
				free(str);
				str = NULL;
				*i = -1;
			}
		}
		a = 0;
	}
}

void	ft_signals_handler(int signum, siginfo_t *info, void *name)
{
	static int	i = 0;
	//static int	count_bit = 0;
	(void)name;

	// printf("le nb de bit %d\n", i);
	if (i < 32)
	{
		ft_len_to_int(signum, i);
	}
	else
	{
		ft_binary_becomes_char(signum, ((i - 32) / 8), (i % 8), &i);
		kill(info->si_pid, SIGUSR1);
	}
	//count_bit++;
	i++;
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
