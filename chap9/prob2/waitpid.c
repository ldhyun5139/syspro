#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() 
{
    int pid1, pid2, child, status;

    printf("[%d] 부모 프로세스 시작 \n", getpid());  // getpid() 괄호 추가
    pid1 = fork();
    if (pid1 == 0) {
        printf("[%d] 자식 프로세스[1] 시작 \n", getpid());
        sleep(1);
        printf("[%d] 자식 프로세스[1] 종료 \n", getpid());
        exit(1);  // 자식 1 종료 코드 1
    }

    pid2 = fork();
    if (pid2 == 0) {
        printf("[%d] 자식 프로세스 #2 시작 \n", getpid());
        sleep(2);
        printf("[%d] 자식 프로세스 #2 종료 \n", getpid());
        exit(2);  // 자식 2 종료 코드 2
    }

    // 자식 프로세스 #1의 종료를 기다린다
    child = waitpid(pid1, &status, 0);
    printf("[%d] 자식 프로세스 #1 %d 종료 \n", getpid(), child);
    printf("\t종료 코드 %d \n",status>>8);  // WEXITSTATUS로 종료 코드 추출
 




		return 0;
}

