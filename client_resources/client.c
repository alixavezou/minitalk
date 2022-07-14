#include "client.h"

char    *g_str;

void    ft_check_pid(char *str)
{
    int    i;

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

void    ft_errors(int argc, char **argv)
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

static void ft_response(int signum, siginfo_t *info, void *context)
{
    int            ret;
    static int    index = 0;
    static int    bit = 7;
    static char    a = 0;

    (void)context;
    if (signum == SIGUSR1)
    {
        write(1, "Well received!\n", 16);
        exit(EXIT_SUCCESS); //exit = quitter le programme, pas besoin de return
    }
    if (a == 0)
        a = g_str[index];
    if (bit >= 0)
    {
        if (a >> bit & 1)
            ret = kill(info->si_pid, SIGUSR1);
        else
            ret = kill(info->si_pid, SIGUSR2);
        if (ret)
        {
            write(2, "Error ret\n", 11);
            exit(EXIT_FAILURE);
        }
        bit--;
    }
    else
    {
        index++;
        bit = 7;
        a = 0;
        ft_response(SIGUSR2, info, NULL);
    }
}

int main(int argc, char **argv)
{
    struct sigaction    sa;
    pid_t    pid;

    ft_errors(argc, argv);
    sigemptyset(&sa.sa_mask);
    sa.sa_sigaction = &ft_response;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    pid = ft_atoi(argv[1]);
    g_str = argv[2];
    kill(pid, SIGUSR1);
    while (1)
        pause();
    return (0);
}
