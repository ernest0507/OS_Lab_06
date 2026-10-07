#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>


extern char **environ;

int main() {
    char command[100];
    char *args[10];

    while(1) {
        fflush(stdout);
        fgets(command, 100, stdin);

        int i = 0;
        args[i] = strtok(command, " \n");

        while (args[i] != NULL && i < 9) {
            i++;
            args[i] = strtok(NULL, " \n");
        }

        if (args[0] == NULL) { continue; }
        if (strcmp(args[0], "exit") == 0) { break; }

        pid_t pid = fork();

        if (pid == 0) {
            char path[100];
            sprintf(path, "/bin/%s", args[0]);
            execve(path, args, environ);

            sprintf(path, "/usr/bin/%s", args[0]);
            execve(path, args, environ);
            perror("execve");
            return 1;
        }
    }
}

