#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>

// On va utiliser une variable globale dans laquelle on va stocker tous les signaux qu'on recevra

// Cette fonction va servir à déterminer le comportement en fonction de SIGUSR1 ou SIGUSR2
// Puis elle transfèrera dans la variable globale le signal qu'elle reçoit
// Puis convertir les int en char (maybe avec ITOA)

void my_handler0(int signal)
{
    write(1, "0", 1);
}

void my_handler1(int signal)
{
    write(1, "1", 1);
}

int main(void)
{
	struct sigaction sa;
	struct sigaction so;

	sa.sa_handler = my_handler0;
	so.sa_handler = my_handler1;
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGUSR1, &so, NULL);
	printf("pid: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
