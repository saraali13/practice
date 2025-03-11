#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define FIFO_NAME "mypipe"

int main() {
    int fd;
    char buffer[100];

    // Open FIFO for reading
    fd = open(FIFO_NAME, O_RDONLY);
    read(fd, buffer, sizeof(buffer));

    printf("Consumer received: %s\n", buffer);

    close(fd);
    return 0;
}

gcc cons2.c -o cons2
./cons2
gcc
