#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX_CMD_LENGTH 1024

void execute_command(char* cmd) {
    pid_t pid = fork();
    
    if (pid == 0) {
        char* args[100];
        char* token = strtok(cmd, " \t\n");
        int i = 0;

        while (token != NULL) {
            args[i++] = token;
            token = strtok(NULL, " \t\n");
        }
        args[i] = NULL;

        if (i > 1 && strcmp(args[i - 2], ">") == 0) {
            int fd = open(args[i - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (fd == -1) {
                perror("Error opening file");
                exit(1);
            }
            dup2(fd, STDOUT_FILENO);
            close(fd);
            args[i - 2] = NULL;
        } else if (i > 1 && strcmp(args[i - 2], "<") == 0) {
            int fd = open(args[i - 1], O_RDONLY);
            if (fd == -1) {
                perror("Error opening file");
                exit(1);
            }
            dup2(fd, STDIN_FILENO);
            close(fd);
            args[i - 2] = NULL;
        }

        if (execvp(args[0], args) == -1) {
            perror("Error executing command");
            exit(1);
        }
    } else if (pid > 0) {
        wait(NULL);
    } else {
        perror("Fork failed");
    }
}

void execute_sequence(char* cmd) {
    char* token = strtok(cmd, ";");
    
    while (token != NULL) {
        execute_command(token);
        token = strtok(NULL, ";");
    }
}

int main() {
    char cmd[MAX_CMD_LENGTH];

    while (1) {
        printf("[shell] ");
        if (fgets(cmd, sizeof(cmd), stdin) == NULL) {
            break;
        }

        cmd[strcspn(cmd, "\n")] = 0;

        if (strlen(cmd) == 0) {
            continue;
        }

        if (cmd[strlen(cmd) - 1] == '&') {
            cmd[strlen(cmd) - 1] = '\0';
            pid_t pid = fork();
            if (pid == 0) {
                execute_command(cmd);
                exit(0);
            }
        } else {
            if (strchr(cmd, ';') != NULL) {
                execute_sequence(cmd);
            } else {
                execute_command(cmd);
            }
        }
    }

    return 0;
}
