#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main() {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    char *str = (char *)shmat(shmid, NULL, 0);  // Attach
    printf("Received: %s\n", str);              // Read data

    shmdt(str);
    shmctl(shmid, IPC_RMID, NULL);  // Destroy shared memory

    return 0;
}
