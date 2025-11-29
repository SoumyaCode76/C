/*
 * LESSON 3: Race Conditions - The Problem
 * 
 * Concepts covered:
 * - Race conditions (when multiple threads access shared data)
 * - Why synchronization is needed
 * - Demonstrating incorrect behavior
 */

#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 10
#define INCREMENTS 100000

// Shared variable - accessed by all threads
int counter = 0;

void* increment_counter(void* arg) {
    int thread_id = *((int*)arg);
    
    for (int i = 0; i < INCREMENTS; i++) {
        // THIS IS DANGEROUS! Multiple threads modifying counter
        // The operation counter++ is actually 3 steps:
        // 1. Read counter value
        // 2. Add 1
        // 3. Write back to counter
        // Another thread can interrupt between these steps!
        counter++;
    }
    
    printf("Thread %d finished\n", thread_id);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    
    printf("Starting with counter = %d\n", counter);
    printf("Expected final value = %d\n", NUM_THREADS * INCREMENTS);
    printf("(Each of %d threads increments %d times)\n\n", NUM_THREADS, INCREMENTS);
    
    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, increment_counter, &thread_ids[i]);
    }
    
    // Wait for all threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    printf("\nFinal counter value = %d\n", counter);
    printf("Expected value      = %d\n", NUM_THREADS * INCREMENTS);
    
    if (counter != NUM_THREADS * INCREMENTS) {
        printf("❌ RACE CONDITION DETECTED! Values don't match!\n");
        printf("Lost updates: %d\n", (NUM_THREADS * INCREMENTS) - counter);
    } else {
        printf("✓ Values match (try running again, race conditions are unpredictable)\n");
    }
    
    return 0;
}

/*
 * EXERCISE:
 * 1. Compile: gcc -pthread 03_race_condition.c -o race_condition
 * 2. Run multiple times - you'll likely get different results each time!
 * 3. This demonstrates WHY we need synchronization
 * 4. Next lesson will show how to fix this with mutexes
 */
