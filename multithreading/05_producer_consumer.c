/*
 * LESSON 5: Producer-Consumer Pattern
 * 
 * Concepts covered:
 * - Condition variables (pthread_cond_t)
 * - pthread_cond_wait(): Wait for a condition
 * - pthread_cond_signal(): Wake up one waiting thread
 * - Classic synchronization pattern
 */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>

#define BUFFER_SIZE 5
#define ITEMS_TO_PRODUCE 20

// Shared buffer
int buffer[BUFFER_SIZE];
int count = 0;  // Number of items in buffer

// Synchronization primitives
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t buffer_not_full = PTHREAD_COND_INITIALIZER;
pthread_cond_t buffer_not_empty = PTHREAD_COND_INITIALIZER;

bool done = false;

void* producer(void* arg) {
    int producer_id = *((int*)arg);
    
    for (int i = 0; i < ITEMS_TO_PRODUCE; i++) {
        int item = i + 1;
        
        pthread_mutex_lock(&mutex);
        
        // Wait while buffer is full
        while (count == BUFFER_SIZE) {
            printf("Producer %d: Buffer full, waiting...\n", producer_id);
            pthread_cond_wait(&buffer_not_full, &mutex);
        }
        
        // Add item to buffer
        buffer[count] = item;
        count++;
        printf("Producer %d: Produced item %d (buffer size: %d)\n", 
               producer_id, item, count);
        
        // Signal that buffer is not empty
        pthread_cond_signal(&buffer_not_empty);
        
        pthread_mutex_unlock(&mutex);
        
        usleep(100000);  // 100ms delay
    }
    
    pthread_mutex_lock(&mutex);
    done = true;
    pthread_cond_broadcast(&buffer_not_empty);  // Wake all consumers
    pthread_mutex_unlock(&mutex);
    
    printf("Producer %d: Finished\n", producer_id);
    return NULL;
}

void* consumer(void* arg) {
    int consumer_id = *((int*)arg);
    
    while (true) {
        pthread_mutex_lock(&mutex);
        
        // Wait while buffer is empty and production not done
        while (count == 0 && !done) {
            printf("Consumer %d: Buffer empty, waiting...\n", consumer_id);
            pthread_cond_wait(&buffer_not_empty, &mutex);
        }
        
        // Exit if production done and buffer empty
        if (count == 0 && done) {
            pthread_mutex_unlock(&mutex);
            break;
        }
        
        // Remove item from buffer
        count--;
        int item = buffer[count];
        printf("Consumer %d: Consumed item %d (buffer size: %d)\n", 
               consumer_id, item, count);
        
        // Signal that buffer is not full
        pthread_cond_signal(&buffer_not_full);
        
        pthread_mutex_unlock(&mutex);
        
        usleep(150000);  // 150ms delay (slower than producer)
    }
    
    printf("Consumer %d: Finished\n", consumer_id);
    return NULL;
}

int main() {
    pthread_t prod_thread, cons_thread;
    int prod_id = 1, cons_id = 1;
    
    printf("Starting Producer-Consumer Demo\n");
    printf("Buffer size: %d\n\n", BUFFER_SIZE);
    
    pthread_create(&prod_thread, NULL, producer, &prod_id);
    pthread_create(&cons_thread, NULL, consumer, &cons_id);
    
    pthread_join(prod_thread, NULL);
    pthread_join(cons_thread, NULL);
    
    printf("\nAll done!\n");
    
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&buffer_not_full);
    pthread_cond_destroy(&buffer_not_empty);
    
    return 0;
}

/*
 * KEY CONCEPTS:
 * - Condition variables allow threads to wait for specific conditions
 * - pthread_cond_wait() atomically releases mutex and waits
 * - Always use condition variables with a mutex
 * - Use while loops (not if) to check conditions
 * 
 * EXERCISE:
 * 1. Compile: gcc -pthread 05_producer_consumer.c -o producer_consumer
 * 2. Observe how producer waits when buffer is full
 * 3. Observe how consumer waits when buffer is empty
 * 4. Try changing BUFFER_SIZE and sleep durations
 */
