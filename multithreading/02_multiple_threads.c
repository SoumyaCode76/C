/*
 * LESSON 2: Working with Multiple Threads
 * 
 * Concepts covered:
 * - Creating multiple threads
 * - Passing different arguments to threads
 * - Thread IDs and identification
 */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void* worker_thread(void* arg) {
    int thread_num = *((int*)arg);
    
    printf("Thread %d: Starting work\n", thread_num);
    
    // Simulate some work
    sleep(thread_num);  // Each thread sleeps for different duration
    
    printf("Thread %d: Finished work\n", thread_num);
    
    return NULL;
}

int main() {
    const int NUM_THREADS = 5;
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
    
    printf("Main: Creating %d threads...\n", NUM_THREADS);
    
    // Create multiple threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_args[i] = i + 1;
        
        if (pthread_create(&threads[i], NULL, worker_thread, &thread_args[i]) != 0) {
            perror("Failed to create thread");
            return 1;
        }
        printf("Main: Thread %d created\n", i + 1);
    }
    
    printf("Main: All threads created. Waiting for completion...\n");
    
    // Wait for all threads to complete
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
        printf("Main: Thread %d joined\n", i + 1);
    }
    
    printf("Main: All threads completed!\n");
    return 0;
}

/*
 * EXERCISE:
 * 1. Compile: gcc -pthread 02_multiple_threads.c -o multiple_threads
 * 2. Run and observe the order threads finish (not creation order!)
 * 3. Modify NUM_THREADS to different values
 * 4. Try to predict which thread will finish first
 */
