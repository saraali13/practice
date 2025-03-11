#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefd[2];
    char buffer[100];
    
    // Create the pipe
    if (pipe(pipefd) == -1) {
        perror("❌ Pipe creation failed");
        return 1;
    }

    // Fork a child process
    pid_t pid = fork();

    if (pid < 0) {
        perror("❌ Fork failed");
        return 1;
    }

    if (pid > 0) {
        // Parent Process
        close(pipefd[0]);  // Close unused read end

        char msg[] = "Hello from Parent!";
        write(pipefd[1], msg, strlen(msg) + 1);

        close(pipefd[1]);  // Close write end after sending data
    } else {
        // Child Process
        close(pipefd[1]);  // Close unused write end

        read(pipefd[0], buffer, sizeof(buffer));
        printf("Child Received: %s\n", buffer);

        close(pipefd[0]);  // Close read end after receiving data
    }

    return 0;
}
