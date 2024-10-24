#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "store.h"
int main(int argc, char *argv[])
{
   int fd;
   struct store record;
   if (argc < 2) {
      fprintf(stderr, "How to use: %s file\n", argv[0]);
      exit(1);
   }
   if ((fd = open(argv[1], O_WRONLY|O_CREAT|O_EXCL, 0640)) == -1) {
      perror(argv[1]);
      exit(2);
   }
   printf("%-2s %-15s %-8s %-4s %-3s\n", "ID", "Name", "category","expired_data", "stock");
   while (scanf("%d %s %s %d %d", &record.id, record.name, record.category, &record.expired_date, &record.stock) == 5) {
      lseek(fd, (record.id - START_ID) * sizeof(record), SEEK_SET);
      write(fd, (char *) &record, sizeof(record) );
   }
   close(fd);
   exit(0);
}


