#include <unistd.h>
#include <stdio.h>
#include <signal.h>
void alarmHandler();

int main( )
{
struct sigaction sa;

	sa.sa_handler = alarmHandler;  
    sa.sa_flags = 0;             
    sigemptyset(&sa.sa_mask);


  sigaction(SIGALRM,&sa,NULL );
  alarm(5);
  short i = 0;
  while (1) {
    sleep(1);
    i++;
    printf("%d second\n", i);
  }
  printf("end\n");
}

void alarmHandler(int signo)
{
   printf("Wake up\n");
   exit(0);
}

