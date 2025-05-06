pthread_mutex_t lock;

void *update(void *arg) {
    pthread_mutex_lock(&lock);
    // critical section
    pthread_mutex_unlock(&lock);
}

sem_t sem;

void *consumer(void *arg) {
    sem_wait(&sem);  // Wait for resource
    // consume
    sem_post(&sem);  // Signal done
}

