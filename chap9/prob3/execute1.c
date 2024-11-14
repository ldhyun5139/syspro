#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* 자식 프로세스를 생성하여 echo 명령어를 실행한다. */
int main( ) 
{
   printf("부모 프로세스 시작\n");
   if (fork( ) == 0) {
      execl("/bin/echo", "echo", "hello", NULL);
      fprintf(stderr,"첫 번째 실패"); 
      exit(1);
   }
   printf("부모 프로세스 끝\n");
}
