#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[])
{
        // tratamento de strings
        char *path = "/home/docker/exercises/";

        char res[strlen(path)+strlen(argv[1])-2];

        strcpy(res, path);
        strcat(res, argv[1]);

        // contexto de processos
        pid_t pid;
        pid = fork();

        if (pid < 0)
        {
                fprintf(stderr, "Erro no fork()");
                exit(-1);
        }
        else if (pid == 0)
        {
                // contexto do filho
                printf("\neu sou o filho\n");
                printf("PID: %d\n", pid);
                printf("Iniciando processo %s\n", argv[1]);
                execl(res, argv[1], (char*)NULL);
        }
        else
        {
                wait(NULL);
                // contexto do pai
                printf("\neu sou o pai\n");
                printf("PID: %d\n", pid);
                exit(0);
        }
}