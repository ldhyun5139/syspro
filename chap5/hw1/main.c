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

void printLine(int line) {
	if (line >= 0 && line < MAX_LINES && strlen(savedText[line]) > 0) {
		printf("%d: %s\n", line + 1, savedText[line]);
	}

	else {
		printf("This is Wrong Line Number.\n");
	}
}

void processInput(char *input, int totalLines) {
	if (strcmp(input, "*") == 0) {
		for (int i = 0; i < totalLines; i++) {
			if (strlen(savedText[i]) > 0) {
				printLine(i);
			}
		}
	}
	else if (strchr(input, ',') != NULL) {
		char *token = strtok(input, ",");

		while (token != NULL) {
			int line = atoi(token) - 1;
			printLine(line);
			token = strtok(NULL, ",");
		}
	}
	else if (strchr(input, '-') != NULL) {
		int start, end;
		sscanf(input, "%d-%d", &start, &end);

		for (int i = start - 1; i <= end - 1 && i < totalLines; i++) {
			printLine(i);
		}
	}

	else {
		int line = atoi(input) - 1;
		printLine(line);
	}
}

int main(int argc, char *argv[]) {
	const char *filename = argv[1];

	int totalLines = readFile(filename);

	printf("File read success\n");
	printf("Total Line: %d\n", totalLines);
	printf("You can choose 1 ~ %d Line\n", totalLines);

	char input[50];
	printf("Pls 'Enter' the line to select: ");
	fgets(input, sizeof(input), stdin);
	input[strcspn(input, "\n")] = '\0';

	processInput(input, totalLines);

	return 0;
}
