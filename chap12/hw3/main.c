#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define MAXLINE 100

int main(){
	int fd[2];
	int pid1, pid2;

	pipe(fd);
	printf("parent process start \n");
	if((pid1 = fork())==0){
	close(fd[0]);

	char input[MAXLINE];
	printf("input string: ");
	fgets(input, MAXLINE, stdin);
	input[strcspn(input, "\n")] = '\0';

	write(fd[1], input, strlen(input) +1);
	close(fd[1]);
	exit(0);
	}

	if((pid2=fork())==0){
	
	close(fd[1]);

	char buffer[MAXLINE];
	read(fd[0], buffer, MAXLINE);
	close(fd[0]);

	 for (int i = 0; buffer[i]; i++) {
            buffer[i] = toupper(buffer[i]);
        }

        printf("%s\n", buffer);
        exit(0);
	}

	close(fd[0]);
	close(fd[1]);

	wait(NULL);
	wait(NULL);

	return 0;



}
