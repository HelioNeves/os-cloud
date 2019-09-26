#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int global = 1;

void main(){
	pid_t cpid;
	siginfo_t siginf;
	int npares = 3;
	int wstatus;

	cpid = fork();
	if(cpid){
		printf("%d\n",cpid);
		int par = 0;
		for(int x = 0; x < npares; x++){
			printf("Numero par: %d\n", par);
			par += 2;
		}
		printf("vou morrer\n");
	}else{
		waitpid(cpid, NULL, 0);
		printf("%d\n",cpid);
		printf("Processo filho morreu\n");
	}
}
