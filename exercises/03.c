#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int global = 1;

void main(){
	int pid;

	pid = fork();
for(;;){
	if(pid){
		printf("Global antes de alterar pelo pai: %p\n", &global);
		global += 2;
		printf("Global depois de alterar pelo pai: %d\n", global);
	}else{
			printf("Global antes de alterar pelo filho: %p\n", &global);
		global += 3;
		printf("Global depois de alterar pelo filho: %d\n", global);
	}
}
}
