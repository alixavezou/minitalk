#include "../ft_printf/ft_printf.h"
#include <signal.h>
#include <limits.h>

char	*g_str = NULL;

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*buffer;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	buffer = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (buffer == NULL)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i] != '\0')
		buffer[i] = s1[i];
	while (s2[++j] != '\0')
		buffer[i + j] = s2[j];
	buffer[i + j] = '\0';
	return (buffer);
}

static void	add_char_to_str(char c)
{
	char	*tempo;
	char	d[2];

	d[0] = c;
	d[1] = '\0';
	tempo = g_str;
	g_str = ft_strjoin(tempo, d);
	free(tempo);
}

void	ft_binary_becomes_char(int signum, siginfo_t *info)
{
	static int	bit = 0;
	static int	str_received = 0;
	static char	a = 0;

	if (signum == SIGUSR1)
		a = a + 1;
	if (signum == SIGUSR2)
		a = a + 0;
	if (++bit == 8)
	{
			add_char_to_str(a);
			if (a == '\0')
			{
				str_received = 1;
				ft_putstr_fd(g_str, 1);
				kill(info->si_pid, SIGUSR1);
				free(g_str);
				g_str = NULL;
			}
			bit = 0;
			a = 0;
	}
	else
		a = a << 1;
	if (str_received == 0)
		kill(info->si_pid, SIGUSR2);
	str_received = 0;
}

static void	ft_signals_handler(int signum, siginfo_t *info, void *unused)
{
	static int	bit = 0;
	static int	started = 0;

	(void)unused;
	if (started == 0)
	{
		if (g_str == NULL)
		{
			g_str = (char *)malloc(sizeof(char));
			if (!g_str)
				return ;
			g_str[0] = '\0';
		}
		started = 1;
		kill(info->si_pid, SIGUSR2);
		return ;
	}
	ft_binary_becomes_char(signum, info);
	if (g_str == NULL)
		started = 0;
	bit++;
	if (bit == 8)
		bit = 0;
}

int main(int argc, char **argv)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	(void)argv;
	if (argc > 1)
	{
		write(2, "error server's pid has too many args\n", 38);
		exit(1);
	}
	ft_printf("server's pid: %d\n", getpid());
	sa.sa_sigaction = &ft_signals_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while(1)
		pause();
	return (0);
}
