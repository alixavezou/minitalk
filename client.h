#ifndef CLIENT_H
# define CLIENT_H

# include <signal.h>
# include <limits.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>

int		ft_atoi(const char *str);
int		ft_char_becomes_binary(pid_t pid, char a);
void	ft_errors(int argc, char **argv);

#endif
