#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>

char *str = NULL; // On va utiliser une variable globale dans laquelle on va stocker tous les char qu'on recevra

// fonction qui va (re)transformer le binaire correspondant à la taille de ma string en int donc on fait l'inverse
void	ft_binary_becomes_int(int signum, int i) //le i s'incrémente à chaque signal reçu
{
	static int	length;

	length = 0;
	if (i < 32)
	{
		length = length << 1;
		if (signum == SIGUSR1)
			length = length + 1;
		if (signum == SIGUSR2)
			length = length + 0;
	}
	if (i == 31) // ca y est on a 1 int
	{
		str = malloc(sizeof(char) * (length + 1)); // on transmet à notre variable globale la string
		if (!str)
			return ;
		length = 0; // on remet à 0 notre length pour accueillir la prochaine string
	}
}

void my_handler(int signal)
{
    if (signal == SIGUSR1)
		write(1, "1", 1);
	else
		write(1, "0", 1);
}

void	ft_signals(int signum)
{
	static int	i; // i = le nombre de signaux que je reçois

	i = 0;
	if (i < 32) //32 bites = la taille de la string transmise
		ft_binary_becomes_int(signum, i);
	//else
		//ft_binary_becomes_char(signum, i);
	i++;
}

int main(void)
{
	struct sigaction sa;

	printf("pid: %d\n", getpid());
	sa.sa_handler = my_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while(1)
		pause();
	return (0);
}
