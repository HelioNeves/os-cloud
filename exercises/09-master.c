#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

int main()
{
        pid_t pid;
        printf("\n\tMASTER PID: %d\n", getpid());

        int slave_id;
        printf("\nEntre com o PID do Slave:");
        scanf("%i", &slave_id);

        while(1){

        int signal_id;
        printf("\nEntre com o ID do IPC desejado:");
        printf("\n1-SIGUSR1\t2-SIGUSR2\t3-SIGTERM\n\t>>");
        scanf("%i", &signal_id);

 	if(signal_id == 1)
                kill(slave_id, SIGUSR1);
        else if(signal_id == 2)
                kill(slave_id, SIGUSR2);
        else if(signal_id == 3)
        {
                kill(slave_id, SIGTERM);
                waitpid(slave_id, NULL, 0);
                printf("\n\nO processo escravo (%d) foi finalizado!", slave_id);
                printf("\nAperte ENTER para finalizar este processo...\n\n");
                getchar();
                exit(0);
        }
        else
        {
                printf("\n>>> ID n encontrado, tente novamente...");
                getchar();
        }
        }

}