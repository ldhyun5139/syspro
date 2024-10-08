#include<stdio.h>
#include<string.h>
#include"copy.h"

char line[5][MAXLINE];
char copyLine[MAXLINE];

int main(){
	int i = 0;

	while(i<5 && fgets(line[i],MAXLINE,stdin)!=NULL)
			{
			

			for(int j = 0; j<i; j++)
			{
				if(strlen(line[i])>strlen(line[j]))
				{
				copy(line[j],copyLine);
				copy(line[i],line[j]);
				copy(copyLine, line[i]);

				}
			}
			i++;
	}

	printf("\n");
	for (int k=0; k<i; k++){
		printf("%s", line[k]);
				}
	return 0;
}



	/*
char line[MAXLINE];
char longest[MAXLINE];

 main(){
	 int len;
	 int max;
	 int count = 0;
	 max = 0;	 
	 while(count <5){
		 if(gets(line)!=NULL)
			 len = strlen(line);
		 len = strlen(line);

		 if(len > max){
			 max = len;
			 copy(line, longest);
		 }
		 count++;
	 }
	 if(max>0)
		 printf("%s \n", longest);

	 return 0;
 }
*/
