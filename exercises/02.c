#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int global = 1;

void main(){
	int pid;

	pid = fork();

	if(pid){
		printf("Global pelo pai: %d\n", global);
	}else{
		printf("Global pelo filho: %d\n", global);
	}
}
