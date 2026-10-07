#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

int main() {
    pid_t pid1 = fork();
    clock_t start1 = clock();

    if (pid1 == 0) {
        double time_ms = (double)(clock() - start1) * 1000 / CLOCKS_PER_SEC;
        printf("child_1: child_pid=%d, parent_pid=%d, time = %.3f\n", getpid(), getppid(), time_ms);
        return 0;
    }

    pid_t pid2 = fork();
    clock_t start2 = clock();

    if (pid2 == 0) {
        double time_ms = (double)(clock() - start2) * 1000 / CLOCKS_PER_SEC;
        printf("child_2: child_pid=%d, parent_pid=%d, time=%.3f\n", getpid(), getppid(), time_ms);
        return 0;
    }

    wait(NULL);
    wait(NULL);

    double time_ms = (double)(clock() - start1) * 1000 / CLOCKS_PER_SEC;
    printf("parent: pid=%d, parent_pid=%d, time=%.3f\n", getpid(), getppid(), time_ms);

    return 0;
}

