#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>

char *str = NULL; // On va utiliser une variable globale dans laquelle on va stocker tous les char qu'on recevra

//fonction pour afficher la string sur le file descriptor
void    ft_putstr_fd(char *s, int fd)
{
    while (*s)
        write(fd, s++, 1);
}

void	ft_binary_becomes_int(int signum, int i)
{
	static int	length = 0;

	if (i < 32)
	{
		length = length << 1;
		if (signum == SIGUSR1)
			length = length + 1;
		if (signum == SIGUSR2)
			length = length + 0;
	}
	if (i == 31) //ca y est on a 1 int
	{
		str = malloc(sizeof(char) * (length + 1)); //on transmet à notre variable globale l'int
		if (!str)
			return ;
		length = 0; //on remet à 0 notre length pour accueillir notre prochain int
	}
}
//Maintenant une fois qu'on a la taille en int il faut convertir le binaire en char pour remplir la str
void	ft_binary_becomes_char(int signum, int bit, int index, int *i)
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
			str[index] = a;
			if (a == '\0')
			{
				ft_putstr_fd(str, 1);
				free(str);
				str = NULL;
				*i = -1;
			}
			a = 0;
		}
	}
}

void	ft_signals_handler(int signum, siginfo_t *info, void *name) //Commonly, the handler function doesn't make any use of the third argument.
{
	static int	i = 0; //i = le nombre de signaux que je reçois
	(void)info;
	(void)name;

	if (i < 32) //32 bites = la taille de la string transmise
		ft_binary_becomes_int(signum, i);
	else
		ft_binary_becomes_char(signum, (i % 8), ((i - 32) / 8), &i);
	i++;
}

int main(void)
{
	struct sigaction sa;

	printf("pid: %d\n", getpid());
	sa.sa_sigaction = ft_signals_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while(1)
		pause();
	return (0);
}
