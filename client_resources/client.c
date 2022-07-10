#include "client.h"

void	send_char_to_server(int pid, char chars, int count_bit)
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
	//usleep(300);
}

static	void send_msg_to_server(struct s_client *client)
{
	static struct s_client *stock;

	if (client)
	{
		stock = client;
		stock->count_bit = 0; //compteur de bits
		stock->chars = 0;//compteur de chars
	}
	else
	{
		stock->count_bit++;

		if (stock->count_bit == 8)
		{
			stock->count_bit = 0;
			stock->chars++;
		}
	}
	if (stock->chars >= ft_strlen(stock->str))
		exit(0);
	send_char_to_server(stock->server_pid, stock->str[stock->chars], stock->count_bit);
	//usleep(300);
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

static void	ft_response(int sig)
{
	(void)sig;
	send_msg_to_server(NULL);
}

int main(int argc, char **argv)
{
	struct	s_client client;
	signal(SIGUSR1, ft_response);
	ft_errors(argc, argv);
	client.server_pid = atoi(argv[1]);
	client.str = argv[2];
	client.count_bit = 0;
	client.chars = 0;

	if (argc == 3)
	{
		send_msg_to_server(&client);
		while(1)
			pause();
		return (0);
	}
}
