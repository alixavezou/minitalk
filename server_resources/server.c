#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>

// On va utiliser une variable globale dans laquelle on va stocker tous les signaux qu'on recevra
// Puis elle transfèrera dans la variable globale le signal qu'elle reçoit
char *str = NULL;

void my_handler(int signal)
{
    if (signal == SIGUSR1)
		write(1, "1", 1);
	else
		write(1, "0", 1);
}

int main(void)
{
	struct sigaction sa;

	printf("pid: %d\n", getpid());
	sa.sa_handler = my_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while(1)
		pause();
	return (0);
}
