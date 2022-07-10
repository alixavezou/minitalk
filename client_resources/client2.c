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
