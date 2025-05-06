#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = shm_open("myshm", O_RDONLY, 0666);
    char *ptr = mmap(0, 1024, PROT_READ, MAP_SHARED, fd, 0);
    printf("Read from shared memory: %s\n", ptr);
    return 0;
}
