#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_LINES 10
#define MAX_LENGTH 100

char savedText[MAX_LINES][MAX_LENGTH];

int readFile(const char *filename) {
	int fd = open(filename, O_RDONLY);

	if (fd == -1) {
		perror("Opening File Error");
		exit(1);
	}

	char buf;
	int line = 0, column = 0;

	while (read(fd, &buf, 1) > 0) {
		if (buf == '\n') {
			savedText[line][column] = '\0';
			line++;
			column = 0;
		}

		else {
			savedText[line][column] = buf;
			column++;
		}

		if (line >= MAX_LINES) {
			break;
		}
	}

	savedText[line][column] = '\0';
	close(fd);

	return line;
}

void print2(int totalLines) {
	for (int i = 0; i <2; i++) {
		printf("%s\n", savedText[i]);
	}
}

void print_choose(){



}
int main(int argc, char *argv[]) {
	if(argc =1){const char *filename = argv[1];
	int totalLines = readFile(filename);
	
	print2(totalLines);
	}

	else if(argc =2){
	const char *filename = argv[2];
	int totalLines = readFile(filename);

	print_choose();
	

	}

	return 0;
}
