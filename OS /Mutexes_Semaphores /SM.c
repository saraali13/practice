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

pthread_mutex_t 
pthread_mutex_init()//initialoze a mutex
pthread_mutex_lock()// lock a mutex
pthread_mutex_unlock()// unloack a mutex
pthread_mutex_destroy()//destory a muntex

sem_t
sem_init() //initialize a semaphore
sem_wait() //dec /wait
sem_post() //inc /signal/termiates
sem_destroy() //destroy
