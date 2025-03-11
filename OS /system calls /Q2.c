#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child process running (PID: %d)\n", getpid());
        sleep(2);
        printf("Child process terminating...\n");
        exit(0);
    } 
    else {
        printf("Parent process waiting for child...\n");
        wait(NULL);
        printf("Child process finished.\n");
    }
    return 0;
}
