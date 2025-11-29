#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define NUM_THREADS 3

pthread_t threads[NUM_THREADS];
int thread_ids[NUM_THREADS];
void * (*thread_function[NUM_THREADS])(void*);

void create_thread_pool() {
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i + 1;
        if (pthread_create(&threads[i], NULL, thread_function[i], &thread_ids[i]) != 0) {
            fprintf(stderr, "Error creating thread %d: %s\n", i + 1, strerror(errno));
            exit(EXIT_FAILURE);
        }
    }
}

void* thread_function1(void* arg) {
    int thread_id = *((int*)arg);
    printf("Thread %d: Starting work... PID: %d\n", thread_id, getpid());
    
    // Simulate some work with sleep
    sleep(2 + (thread_id % 3));  // Sleep between 2-4 seconds
    
    printf("Thread %d: Work completed!\n", thread_id);
    return NULL;
}

void* thread_function2(void* arg) {
    int thread_id = *((int*)arg);
    printf("Thread %d: Starting work... PID: %d\n", thread_id, getpid());
    
    // Simulate some work with sleep
    sleep(2 + (thread_id % 3));  // Sleep between 2-4 seconds
    
    printf("Thread %d: Work completed!\n", thread_id);
    return NULL;
}

void* thread_function3(void* arg) {
    int thread_id = *((int*)arg);
    printf("Thread %d: Starting work... PID: %d\n", thread_id, getpid());
    
    // Simulate some work with sleep
    sleep(2 + (thread_id % 3));  // Sleep between 2-4 seconds
    
    printf("Thread %d: Work completed!\n", thread_id);
    return NULL;
}

int main(void){
    // Assign functions to thread function pointers
    thread_function[0] = thread_function1;
    thread_function[1] = thread_function2;
    thread_function[2] = thread_function3;

    printf("Main: Creating thread pool with %d threads...\n", NUM_THREADS);
    create_thread_pool();

    // Wait for all threads to complete
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
        printf("Main: Thread %d joined\n", i + 1);
    }

    printf("Main: All threads completed!\n");
    return 0;
}