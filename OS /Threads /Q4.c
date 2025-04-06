#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function that will run in the new thread
void *print_message(void *arg) {
    char *message = (char *) arg;
    printf("Thread says: %s\n", message);
    return NULL;
}

int main() {
    pthread_t thread_id;      // Thread identifier
    char *msg = "Hello from thread!";

    // Create a new thread
    if (pthread_create(&thread_id, NULL, print_message, (void *) msg) != 0) {
        perror("Failed to create thread");
        return 1;
    }

    // Wait for the thread to complete
    pthread_join(thread_id, NULL);

    printf("Main program ends\n");
    return 0;
}
