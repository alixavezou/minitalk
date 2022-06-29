#ifndef CLIENT_H
# define CLIENT_H

# include <signal.h>
# include <limits.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>

size_t	ft_strlen(const char *str);

int		ft_atoi(const char *str);
int		ft_char_becomes_binary(char a, pid_t pid);
int		ft_int_becomes_binary(int a, pid_t pid);
void	ft_errors(int argc, char **argv);
void	ft_check_pid(char *str);
void	ft_check_pid_max(int argc, char **argv);

#endif
