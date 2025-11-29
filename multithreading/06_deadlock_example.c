/*
 * LESSON 6: Deadlock - The Problem and Solution
 * 
 * Concepts covered:
 * - What is deadlock
 * - How deadlock occurs
 * - How to prevent deadlock
 */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;

// DEADLOCK VERSION - Don't run this unless you want to see a deadlock!
void* thread1_deadlock(void* arg) {
    printf("Thread 1: Trying to acquire mutex1...\n");
    pthread_mutex_lock(&mutex1);
    printf("Thread 1: Acquired mutex1\n");
    
    sleep(1);  // Simulate some work
    
    printf("Thread 1: Trying to acquire mutex2...\n");
    pthread_mutex_lock(&mutex2);  // WILL BLOCK FOREVER!
    printf("Thread 1: Acquired mutex2\n");
    
    // Do some work...
    
    pthread_mutex_unlock(&mutex2);
    pthread_mutex_unlock(&mutex1);
    return NULL;
}

void* thread2_deadlock(void* arg) {
    printf("Thread 2: Trying to acquire mutex2...\n");
    pthread_mutex_lock(&mutex2);
    printf("Thread 2: Acquired mutex2\n");
    
    sleep(1);  // Simulate some work
    
    printf("Thread 2: Trying to acquire mutex1...\n");
    pthread_mutex_lock(&mutex1);  // WILL BLOCK FOREVER!
    printf("Thread 2: Acquired mutex1\n");
    
    // Do some work...
    
    pthread_mutex_unlock(&mutex1);
    pthread_mutex_unlock(&mutex2);
    return NULL;
}

// SOLUTION - Lock in consistent order
void* thread1_fixed(void* arg) {
    printf("Thread 1: Trying to acquire mutex1...\n");
    pthread_mutex_lock(&mutex1);
    printf("Thread 1: Acquired mutex1\n");
    
    sleep(1);
    
    printf("Thread 1: Trying to acquire mutex2...\n");
    pthread_mutex_lock(&mutex2);
    printf("Thread 1: Acquired mutex2\n");
    
    printf("Thread 1: Working with both locks...\n");
    sleep(1);
    
    pthread_mutex_unlock(&mutex2);
    pthread_mutex_unlock(&mutex1);
    printf("Thread 1: Released both locks\n");
    return NULL;
}

void* thread2_fixed(void* arg) {
    printf("Thread 2: Trying to acquire mutex1...\n");  // Same order!
    pthread_mutex_lock(&mutex1);
    printf("Thread 2: Acquired mutex1\n");
    
    sleep(1);
    
    printf("Thread 2: Trying to acquire mutex2...\n");
    pthread_mutex_lock(&mutex2);
    printf("Thread 2: Acquired mutex2\n");
    
    printf("Thread 2: Working with both locks...\n");
    sleep(1);
    
    pthread_mutex_unlock(&mutex2);
    pthread_mutex_unlock(&mutex1);
    printf("Thread 2: Released both locks\n");
    return NULL;
}

int main() {
    pthread_t t1, t2;
    int choice;
    
    printf("Deadlock Demo\n");
    printf("1. Run DEADLOCK version (will hang!)\n");
    printf("2. Run FIXED version (works correctly)\n");
    printf("Choice: ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("\n*** WARNING: This will deadlock! Press Ctrl+C to exit ***\n\n");
        sleep(2);
        pthread_create(&t1, NULL, thread1_deadlock, NULL);
        pthread_create(&t2, NULL, thread2_deadlock, NULL);
    } else {
        printf("\n*** Running fixed version ***\n\n");
        pthread_create(&t1, NULL, thread1_fixed, NULL);
        pthread_create(&t2, NULL, thread2_fixed, NULL);
    }
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    
    printf("\nProgram completed successfully!\n");
    
    pthread_mutex_destroy(&mutex1);
    pthread_mutex_destroy(&mutex2);
    
    return 0;
}

/*
 * DEADLOCK PREVENTION STRATEGIES:
 * 1. Lock ordering - Always acquire locks in same order
 * 2. Lock timeout - Use pthread_mutex_trylock() with timeout
 * 3. Avoid holding multiple locks when possible
 * 4. Use higher-level synchronization primitives
 * 
 * EXERCISE:
 * 1. Compile: gcc -pthread 06_deadlock_example.c -o deadlock_example
 * 2. Run option 2 first to see correct behavior
 * 3. (Optional) Run option 1 to see deadlock (Ctrl+C to exit)
 * 4. Understand why lock ordering prevents deadlock
 */
