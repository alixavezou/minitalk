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

// cette fonction va gérer les éventuelles erreurs
void	ft_errors(int argc, char **argv)
{
	int	i;

	i = 0;
	// il faut d'abord s'assurer que le nb d'args est bien = à 3
	if (argc != 3)
	{
		write(1, "wrong numbers of arguments\n", 28);
		exit(1);
	}
	if (argv[1][0] == '\0')
	{
		write(1, "no PID\n", 8);
		exit(1);
	}
	// verifier que le PID est bien compris entre 0 et 9
	// + le PID ne doit pas etre = 0 ou à -1
	if (!(argv[1][i] >= '0' && argv[1][i] <= '9'))
	{
		write(1, "problem with the PID\n", 22);
		exit(1);
	}
	else
		i++;
}

int main(int argc, char **argv)
{
	int		i;
	pid_t	pid;

	i = 0;
	// Il faut transormer le PID en int car il va être transmis en tant que string alors que c'est un int.
	//Car meme si tu envoies des numeros dans le terminal l'argument 1 sera considéré comme une chaine de char
	pid = atoi(argv[1]);
	ft_errors(argc, argv);
	if (argc == 3) // donc, si j'ai bien mon executable + mes 2 args on peut envoyer un signal à mon serveur
	{
		while(argv[2][i] != '\0') // tant qu'il y a bien des char dans ma string donc dans mon 2e argument après le PID
		{
			ft_char_becomes_binary(pid, argv[2][i]); // on procede bien a la conversion de ma string
			i++;
		}
		ft_char_becomes_binary('\0', pid); // on oublie pas d'inclure le '\0' une fois qu'il n'y a plus de char
	}
	return (0);
}
// verifier ce que retourne la fonction kill au cas ou il y a une erreur (= à -1)
