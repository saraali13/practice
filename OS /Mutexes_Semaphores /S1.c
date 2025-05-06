#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t empty, full;//Semaphore
pthread_mutex_t lock;//Used to avaoid race condition between producer and consumer
int buffer[5];
int count = 0;

void* producer(void* arg) {
    while (1) {
        sem_wait(&empty); // Wait for empty slot
        pthread_mutex_lock(&lock);
        buffer[count++] = 1; // Add item
        printf("Produced item. Count: %d\n", count);
        pthread_mutex_unlock(&lock);
        sem_post(&full); // Increase full count
        sleep(1);
    }
}

void* consumer(void* arg) {
    while (1) {
        sem_wait(&full); // Wait for item
        pthread_mutex_lock(&lock);
        buffer[--count] = 0; // Remove item
        printf("Consumed item. Count: %d\n", count);
        pthread_mutex_unlock(&lock);
        sem_post(&empty); // Increase empty count
        sleep(1);
    }
}

int main() {
    pthread_t p, c;
    sem_init(&empty, 0, 5);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&lock, NULL);

    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);
}
