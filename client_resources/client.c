# include "client.h"

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
}
void	ft_int_becomes_binary(int a, pid_t pid) // int a = la taille de ma string
{
	int	i;
	int	bit;

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
		usleep(150);
		i--;
	}
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

int main(int argc, char **argv)
{
	int		i;
	pid_t	pid;

	i = 0;
	ft_errors(argc, argv);
	pid = atoi(argv[1]);
	if (argc == 3)
	{
		ft_int_becomes_binary(ft_strlen(argv[2]), pid);
		while(argv[2][i] != '\0')
		{
			ft_char_becomes_binary(argv[2][i], pid);
			i++;
		}
		ft_char_becomes_binary('\0', pid);
	}
	return (0);
}
