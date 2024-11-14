 #include <stdio.h>
 #include <unistd.h>


 int main()
 {    
     printf("나의 프로세스 번호 : [%d] \n", getpid());
     printf("내 부모 프로세스 번호 : [%d] \n", getppid());
}

