#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

void main(){
	pid_t cpid;
	char input[100];
	int pip[2];

	if(pipe(pip) < 0)
		exit(1);

	cpid = fork();
	if(!cpid){
		wait(NULL);
		close(pip[1]);
		char output[100];
		read(pip[0], output, 100);
		printf("Pai: %s\n", output);
		close(pip[0]);
	}else{
		close(pip[0]);
		printf("Filho:\n");
		scanf("%s", input);
		printf("\n");
		write(pip[1], input, strlen(input)+1);
		close(pip[1]);
	}
}
