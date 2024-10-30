#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    int show_line_numbers = 0;
	int c;
    int line_number = 1;
    int file_index = 1;

	if (argc > 1 && strcmp(argv[1], "-n") == 0) {
        show_line_numbers = 1;
        file_index = 2;
	}

    for (int i = file_index; i < argc; i++) {
        fp = fopen(argv[i], "r");
        if (fp == NULL) {
            fprintf(stderr, "File %s Open Error\n", argv[i]);
            continue;
		}

        if (show_line_numbers) {
            printf("%6d  ", line_number++);
        }

        while ((c = getc(fp)) != EOF) {
            putchar(c);
            if (show_line_numbers && c == '\n' && !feof(fp)) {
				if ((c = getc(fp)) != EOF) {
					 printf("%6d  ", line_number++);
					 ungetc(c, fp);
				}
            }
        }

        fclose(fp);
        line_number = 1;
	}

    return 0;
}
