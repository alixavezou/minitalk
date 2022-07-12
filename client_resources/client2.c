#include "client.h"

void	send_char(int pid, char chars, int count_bit)
{
	if (chars & (128 >> count_bit))
	{
		if (kill(pid, SIGUSR1) == -1)
			exit(1);
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
			exit(1);
	}
}

void	ft_len_to_binary(int a, pid_t pid)
{
	int	i;
	int bit;

	i = 31;
	bit = 0;
	while (i >= 0)
	{
		bit = (a >> i) & 1;
		if (bit == 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		i--;
		usleep(150);
	}
}
