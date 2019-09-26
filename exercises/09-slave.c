#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

void my_handler(int signum)
{
    if (signum == SIGUSR1)
    {
        printf("Recebeu SIGUSR1!\n");
    }
    else if (signum == SIGUSR2)
    {
        printf("Recebeu SIGUSR2!\n");
    }
    else if (signum == SIGTERM)
    {
        printf("Recebeu SIGTERM!\n");
        exit(0);
    }

}

int main()
{
        pid_t pid;
        printf("\n\tSLAVE PID: %d\n", getpid());

        signal(SIGUSR1, my_handler);
        signal(SIGUSR2, my_handler);
        signal(SIGTERM, my_handler);

        for(;;);
}