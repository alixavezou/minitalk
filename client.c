#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void	send_string(pid_t	pid, int c) // cette fonction va servir à envoyer le PID & la string passée en param du client vers le serveur
{

}

int main(int argc, char **argv)
{
	int		i;
	pid_t	pid;

	i = 0;
	if (argc != 3)
		exit(1);
}

// il va falloir créer une fonction qui gère les erreurs 
