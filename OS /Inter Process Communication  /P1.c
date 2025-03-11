#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefd[2];      // pipefd[0] - read end, pipefd[1] - write end
    pid_t pid;          
    char message[] = "Hello from Producer!";
    char buffer[100];

    // Create pipe
    if (pipe(pipefd) == -1) {
        perror("Pipe creation failed");
        return 1;
    }

    // Fork to create child process
    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid > 0) { // Parent (Producer)
        close(pipefd[0]);  // Close unused read end
        write(pipefd[1], message, strlen(message) + 1); // Write message
        close(pipefd[1]);  // Close write end
    } else { // Child (Consumer)
        close(pipefd[1]);  // Close unused write end
        read(pipefd[0], buffer, sizeof(buffer)); // Read message
        printf("Consumer received: %s\n", buffer);
        close(pipefd[0]);  // Close read end
    }

    return 0;
}

gcc p1.c -o p1
./p1
