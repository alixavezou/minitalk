#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <limits.h>

// cette fonction va s'occuper de transformer la string en binaire pour que ce soit compréhensible pour le serveur
int	ft_char_becomes_binary(pid_t pid, char a)
{
	int	i;
	int bit;

	i = 7;
	bit = 0;
	while (i >= 0)
	{
		if ((a >> i) & 1)
			bit = kill(pid, SIGUSR1);
		else
			bit = kill(pid, SIGUSR2);
		if (bit)
		{
			write(1, "error\n", 7);
			exit(1);
		}
		usleep(200);
		i--;
	}
}

int main(int argc, char **argv)
{
	int		i;
	pid_t	pid;
	//char	c;

	//pid = 123;
	//c = 'L';
	//i = ft_char_becomes_binary(pid, c);
	if (argc != 3)
		exit(1);
}

// il va falloir créer une fonction qui gère les erreurs
// verifier que le PID != 0 ou à -1
