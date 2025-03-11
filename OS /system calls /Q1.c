#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid;
    pid = fork(); // Creating a new process

    if (pid < 0) {
        printf("Fork failed!\n");
        exit(1);
    }
        //getppid() for their own id 
    else if (pid == 0) {
        printf("Child process, PID: %d\n", getpid());// shows parent id
        
    }
    else {
        printf("Parent process, PID: %d\n", getpid());// shows child id
    }
    return 0;
}
