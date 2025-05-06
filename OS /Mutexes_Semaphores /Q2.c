sem_t mutex, rw_mutex;
int readers_count = 0;

void *reader(void *arg) {
    while (1) {
        sem_wait(&mutex);
        readers_count++;
        if (readers_count == 1)
            sem_wait(&rw_mutex); // First reader blocks writers
        sem_post(&mutex);

        // Read file logic
        // ...

        sem_wait(&mutex);
        readers_count--;
        if (readers_count == 0)
            sem_post(&rw_mutex); // Last reader unblocks writers
        sem_post(&mutex);
        usleep(1000);
    }
}
