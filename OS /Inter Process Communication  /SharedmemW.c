#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main() {
    key_t key = ftok("shmfile", 65);  // Generate a unique key
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);  // Create shared memory

    char *str = (char *)shmat(shmid, NULL, 0);  // Attach
    sprintf(str, "Hello from writer!");          // Write data
    shmdt(str);                                 // Detach

    return 0;
}
