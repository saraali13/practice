#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#define FIFO_NAME "mypipe"

int main() {
    int fd;
    char message[] = "Data from Producer to Consumer";

    // Create named pipe (FIFO)
    mkfifo(FIFO_NAME, 0666);

    // Open FIFO for writing
    fd = open(FIFO_NAME, O_WRONLY);
    write(fd, message, strlen(message) + 1);
    
    printf("Producer: Data written to FIFO.\n");

    close(fd);
    return 0;
}

gcc prod2.c -o prod
./prod
