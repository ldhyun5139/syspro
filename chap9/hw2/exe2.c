#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAXCMD 1024
#define MAXARG 100

void execute_command(char* cmd) {
    char* args[MAXARG];
    char* token;
    int background = 0;

    token = strtok_r(cmd, " \t\n", &cmd);
    int i = 0;

    while (token != NULL) {
        args[i++] = token;
        token = strtok_r(NULL, " \t\n", &cmd);
    }
    args[i] = NULL;

    if (i > 0 && strcmp(args[i - 1], "&") == 0) {
        args[i - 1] = NULL;
        background = 1;
    }

    pid_t pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("Error executing command");
            exit(1);
        }
    } else if (pid > 0) {
        if (!background) {
            wait(NULL);
        }
    } else {
        perror("Fork failed");
        exit(1);
    }
}

int main() {
    char cmd[MAXCMD];

    while (1) {
        printf("[Shell] ");
        if (fgets(cmd, sizeof(cmd), stdin) == NULL) {
            break;
        }

        cmd[strcspn(cmd, "\n")] = 0;

        if (strlen(cmd) == 0) {
            continue;
        }

        execute_command(cmd);
    }

    return 0;
}
