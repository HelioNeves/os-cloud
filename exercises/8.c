#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void main(int argc, char *argv[])
{
	int pdes[2];
	int pd[2];
	int status;
	float args_parent;
	pid_t pid;
	pipe(pd); 
	pipe(pdes);
	pid = fork();
	float args_child;

	if ( pid>0 ) { /* parent process - producer */
		do{
			close(pdes[0]);
			printf("\nDigite o número\n");
			scanf("%f", &args_parent);
			if(args_parent==0){
				kill( pid, SIGKILL );		
				exit(0);}
			else{
				write( pdes[1], &args_parent, sizeof(args_parent));
				wait(NULL);
				float resultado2;
				read(pd[0], &resultado2, sizeof(resultado2));
				printf("O Resultado:\n");
				printf("%.2f\n", resultado2);
				close(pdes[1]);
				close(pd[0]);
				}

		}while(args_parent!=0);
		kill(pid, SIGKILL);

	} else if (pid==0) {/* child process - consumer */ 
		
			float resultado;				
			close(pdes[1]); 
			read( pdes[0], &args_child, sizeof(args_child)); /* read from parent */	
			float numero = atof(argv[2]);
			
			pid = waitpid(pid, &status, 0);
				
			if(!strcmp(argv[1],"-a")){
				resultado = numero+args_child;
			}
			else if(!strcmp(argv[1],"-s")){
				resultado = numero-args_child;
			}
			else if(!strcmp(argv[1],"-m")){
				resultado = numero*args_child;
			}
			else if(!strcmp(argv[1],"-d")){
				resultado = numero/args_child;
			}
			else{
				exit(-1);
			}
			close(pdes[0]);
			write(pd[1], &resultado, sizeof(resultado));
			close(pd[1]);
	} 
		else {
			exit(-1);
	}

	exit(0);
}
