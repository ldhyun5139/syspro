#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "store.h"
 
  int main(int argc, char *argv[])
  {
     int fd, num;
      char c;
     struct student record;
     if (argc < 2) {
        fprintf(stderr,"How to use : %s file\n", argv[0]);
        exit(1);
     }
     if ((fd = open(argv[1], O_RDONLY)) == -1) {
        perror(argv[1]);
        exit(2);
     }
     do {
        printf("0: list of all goods, 1: list of available goods");
        scanf("%d",&num);

		if (num == 0) {// 0 all print
			pritf("%10s %15s %6s %4s %3s","id","category","expired_date","stock");
			while(fread(&fd(&record,sizeof(record),1,fd)>0
						if(record.id!=0)
							printf("%2d %15s %6s %4d %3d", record.id, record.name, record.category, record.expired_date, record.stock);

        }

		else (num ==0){
		

		}




		else printf("Input Error");
        printf("Continue?(Y/N)");
        scanf(" %c", &c);
     } while (c=='Y');
     close(fd);
     exit(0);
  }
 

