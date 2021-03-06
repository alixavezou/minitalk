#ifndef CLIENT_H
# define CLIENT_H

# include <signal.h>
# include <limits.h>
# include "../ft_printf/ft_printf.h"

int		ft_strlen(char *str);
int		ft_atoi(const char *str);
void	ft_errors(int argc, char **argv);
void	ft_check_pid(char *str);

#endif
