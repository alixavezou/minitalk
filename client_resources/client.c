#include "client.h"

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
			write(2, "problem with the PID\n", 22);
			exit(1);
		}
	}
}

void	ft_errors(int argc, char **argv)
{
	if (argc != 3)
	{
		write(2, "wrong numbers of arguments\n", 28);
		exit(1);
	}
	if (argv[1][0] == '\0')
	{
		write(2, "no PID\n", 8);
		exit(1);
	}
	if ((ft_atoi(argv[1]) <= 0) || (ft_atoi(argv[1]) > 4194304))
	{
		write(2, "problem of PID\n", 16);
		exit(1);
	}
	ft_check_pid(argv[1]);
}

static void ft_response(int signum, siginfo_t *info, void *unused)
{
	(void)signum;
	(void)info;
	(void)unused;
	write(1, "Well received!\n", 16);
	exit(0);
	return ;
}

static void	ft_handle_sig_back(void)
{
	struct sigaction sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_response;
	sigaction(SIGUSR1, &sa, NULL);
}

int main(int argc, char **argv)
{
	int	i;

	ft_handle_sig_back();
	pid_t	pid;
	i = 0;
	ft_errors(argc, argv);
	pid = ft_atoi(argv[1]);
	ft_len_to_binary(ft_strlen(argv[2]), pid);

	while (argv[2][i])
	{
		ft_send_char(argv[2][i], pid);
		i++;
	}
	ft_send_char('\0', pid);
	while (1)
		pause();
	return (0);
}
