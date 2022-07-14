#ifndef SERVER_H
# define SERVER_H

# include <signal.h>
# include <limits.h>
# include "../ft_printf/ft_printf.h"

int		ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putstr_fd(char *s, int fd);
void	ft_binary_becomes_char(int signum, siginfo_t *info);

#endif
