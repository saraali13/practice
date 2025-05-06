#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZE 8             // Total elements in array
#define NUM_THREADS 4      // Number of threads

int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8};
int partial_sum[NUM_THREADS] = {0};

void* sum_array(void* arg) {
    int thread_part = *(int*)arg;
    int start = thread_part * (SIZE / NUM_THREADS);
    int end = start + (SIZE / NUM_THREADS);

    for (int i = start; i < end; i++) {
        partial_sum[thread_part] += arr[i];
    }

    pthread_exit(0);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    int total_sum = 0;

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, sum_array, &thread_ids[i]);
    }

    // Wait for threads to complete
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
        total_sum += partial_sum[i];
    }

    printf("Total Sum = %d\n", total_sum);
    return 0;
}
