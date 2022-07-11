#ifndef CLIENT_H
# define CLIENT_H

# include <signal.h>
# include <limits.h>
# include "../ft_printf/ft_printf.h"

struct		s_client
{
	int		server_pid;
	int		count_bit;
	int		chars;
	char	*str;
};

int		ft_strlen(char *str);
int		ft_atoi(const char *str);

void	ft_errors(int argc, char **argv);
void	ft_check_pid(char *str);
void	send_char(int pid, char chars, int count_bit);
void	ft_len_to_binary(int a, pid_t pid);

#endif
