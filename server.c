#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void my_handler(int signal) {
    write(1, "Received SIGUSR1!\n", 18);
}

int main()
{
	signal(SIGUSR1, my_handler);
	printf("pid: %d\n", getpid());
	while (1)
	{
		sleep(1);
	}
}
