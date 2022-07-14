// #include "client.h"

// void	ft_len_to_binary(int a, pid_t pid)
// {
// 	int	i;
// 	int	ret;

// 	i = 31;
// 	while (i >= 0)
// 	{
// 		if ((a >> i) & 1)
// 			ret = (kill(pid, SIGUSR1));
// 		else
// 			ret = (kill(pid, SIGUSR2));
// 		if (ret)
// 		{
// 			write(2, "Error ret\n", 11);
// 			exit(1);
// 		}
// 		usleep(30);
// 		i--;
// 	}
// 	usleep(300);
// }
