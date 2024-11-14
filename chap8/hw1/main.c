#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void print_env_variable(char *name) {
    if (name) {
        char *value = getenv(name);
        if (value) {
            printf("%s: %s\n", name, value);
        } else {
            printf("환경변수 %s가 존재하지 않습니다.\n", name);
        }
    } else {
        extern char **environ;
        for (char **env = environ; *env != NULL; env++) {
            printf("%s\n", *env);
        }
    }
}

void print_user_ids() {
    printf("실제 사용자 ID: %d\n", getuid());
    printf("유효 사용자 ID: %d\n", geteuid());
}

void print_group_ids() {
    printf("실제 그룹 ID: %d\n", getgid());
    printf("유효 그룹 ID: %d\n", getegid());
}

void print_process_id() {
    printf("프로세스 ID: %d\n", getpid());
}

void print_parent_process_id() {
    printf("부모 프로세스 ID: %d\n", getppid());
}

int main(int argc, char *argv[]) {
    int opt;
    while ((opt = getopt(argc, argv, "e::ugip")) != -1) {
        switch (opt) {
            case 'e':
                if (optarg) {
                    print_env_variable(optarg);
                } else {
                    print_env_variable(NULL);
                }
                break;
            case 'u':
                print_user_ids();
                break;
            case 'g':
                print_group_ids();
                break;
            case 'i':
                print_process_id();
                break;
            case 'p':
                print_parent_process_id();
                break;
            default:
                fprintf(stderr, "사용법: %s [-e[환경변수이름]] [-u] [-g] [-i] [-p]\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }
    return 0;
}

