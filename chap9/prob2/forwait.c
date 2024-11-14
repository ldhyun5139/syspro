#include <stdlib.h>
#include <sys/types.h>
#include<sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	int pid1, pid2, child, status;

	printf("[%d] parental process start\n",getpid());
	pid1=fork();



	if(pid1==0){
	printf("[%d] child process start\n",getpid());
	exit(1);
	}
	child = wait(&status);
	printf("[%d] child process %d end\n", getpid(), child);
	printf("\t end code %d \n", status>>8);




	}
