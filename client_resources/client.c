# include "client.h"

// cette fonction va s'occuper de transformer la string en binaire pour que ce soit compréhensible pour le serveur
void	ft_char_becomes_binary(char a, pid_t pid)
{
	int	i;
	int bit;

	i = 7;
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
		usleep(150);
		i--;
	}
	usleep(300000);
}
// cette fonction va transformer l'int correspondant à la taille de ma string en binaire pour la passer au serveur
void	ft_int_becomes_binary(int a, pid_t	pid)
{
	int	i;
	int	bit;

	i = 31; // 1 int = 32 bits
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
		usleep(150);
		i--;
	}
	//usleep(300000);
}

void	ft_check_pid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
		{
			write(1, "problem with the PID\n", 22);
			exit(1);
		}
	}
}

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
	if ((ft_atoi(argv[1]) == 0) || (ft_atoi(argv[1]) > INT_MAX))
	{
		write(1, "problem of PID\n", 16);
		exit(1);
	}
	ft_check_pid(argv[1]);
}
// il faudra gérer le cas ou le atoi du PID est != 0 et > INT_MAX(overflow).
//Le pid ne peut pas etre = 0. if atoi(argv[1] == 0) = faux.

int main(int argc, char **argv)
{
	int		i;
	pid_t	pid;

	i = 0;
	// Il faut transormer le PID en int car il va être transmis en tant que string alors que c'est un int.
	//Car meme si tu envoies des numeros dans le terminal l'argument 1 sera considéré comme une chaine de char
	ft_errors(argc, argv);
	pid = atoi(argv[1]);
	if (argc == 3) // donc, si j'ai bien mon executable + mes 2 args on peut envoyer un signal à mon serveur
	{
		ft_int_becomes_binary(ft_strlen(argv[2]), pid);
		while(argv[2][i] != '\0') // tant qu'il y a bien des char dans ma string donc dans mon 2e argument après le PID
		{
			ft_char_becomes_binary(argv[2][i], pid); // on procede bien a la conversion de ma string
			i++;
		}
		//ft_char_becomes_binary('\0', pid); // on oublie pas d'inclure le '\0' une fois qu'il n'y a plus de char
	}
	return (0);
}
