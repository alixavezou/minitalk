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
void	ft_check_pid_max(int argc, char **argv);
void	send_char_to_server(int pid, char chars, int count_bit);

#endif
