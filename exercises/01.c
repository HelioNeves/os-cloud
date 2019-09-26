#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

void main(){
	int pid;

	pid = fork();

	if(pid){
		printf("eu sou o pai \t %d \n", getpid());
	}else{
		printf("eu sou o filho \t %d \n", getpid());
	}
}	
