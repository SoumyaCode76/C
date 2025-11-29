/*
 * LESSON 4: Mutex - Fixing Race Conditions
 * 
 * Concepts covered:
 * - pthread_mutex_t: Mutual exclusion lock
 * - pthread_mutex_lock(): Acquire lock
 * - pthread_mutex_unlock(): Release lock
 * - Critical section protection
 */

#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 10
#define INCREMENTS 100000

int counter = 0;
pthread_mutex_t mutex;  // Mutex to protect counter

void* increment_counter_safe(void* arg) {
    int thread_id = *((int*)arg);
    
    for (int i = 0; i < INCREMENTS; i++) {
        // LOCK the mutex before accessing shared data
        pthread_mutex_lock(&mutex);
        
        // CRITICAL SECTION - only one thread can be here at a time
        counter++;
        
        // UNLOCK the mutex after we're done
        pthread_mutex_unlock(&mutex);
    }
    
    printf("Thread %d finished\n", thread_id);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    
    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);
    
    printf("Starting with counter = %d\n", counter);
    printf("Expected final value = %d\n\n", NUM_THREADS * INCREMENTS);
    
    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, increment_counter_safe, &thread_ids[i]);
    }
    
    // Wait for all threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    printf("\nFinal counter value = %d\n", counter);
    printf("Expected value      = %d\n", NUM_THREADS * INCREMENTS);
    
    if (counter == NUM_THREADS * INCREMENTS) {
        printf("✓ SUCCESS! Mutex protected the shared data!\n");
    } else {
        printf("❌ Something went wrong: %d\n", (NUM_THREADS * INCREMENTS) - counter);
    }
    
    // Clean up the mutex
    pthread_mutex_destroy(&mutex);
    
    return 0;
}

/*
 * KEY CONCEPTS:
 * - Mutex = Mutual Exclusion
 * - Only ONE thread can hold the lock at a time
 * - Other threads wait (block) until lock is available
 * - Always unlock what you lock!
 * 
 * EXERCISE:
 * 1. Compile: gcc -pthread 04_mutex_basics.c -o mutex_basics
 * 2. Run multiple times - result should ALWAYS be correct now
 * 3. Compare execution time with 03_race_condition.c (this is slower - why?)
 */
