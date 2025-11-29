/*
 * LESSON 7: Thread Pool Pattern
 * 
 * Concepts covered:
 * - Thread pool for efficient task processing
 * - Task queue with work distribution
 * - Practical real-world pattern
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>

#define THREAD_POOL_SIZE 4
#define MAX_QUEUE_SIZE 100

// Task structure
typedef struct {
    void (*function)(int);
    int argument;
} Task;

// Task queue
Task task_queue[MAX_QUEUE_SIZE];
int queue_size = 0;
int queue_front = 0;
int queue_rear = 0;

pthread_mutex_t queue_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t queue_not_empty = PTHREAD_COND_INITIALIZER;
bool shutdown = false;

// Example task functions
void process_task(int task_id) {
    printf("  [Worker %lu] Processing task %d...\n", pthread_self() % 10000, task_id);
    sleep(1 + (task_id % 3));  // Simulate work (1-3 seconds)
    printf("  [Worker %lu] Completed task %d\n", pthread_self() % 10000, task_id);
}

void compute_task(int value) {
    printf("  [Worker %lu] Computing %d^2...\n", pthread_self() % 10000, value);
    sleep(1);
    printf("  [Worker %lu] Result: %d^2 = %d\n", pthread_self() % 10000, value, value * value);
}

// Add task to queue
void submit_task(void (*func)(int), int arg) {
    pthread_mutex_lock(&queue_mutex);
    
    if (queue_size < MAX_QUEUE_SIZE) {
        task_queue[queue_rear].function = func;
        task_queue[queue_rear].argument = arg;
        queue_rear = (queue_rear + 1) % MAX_QUEUE_SIZE;
        queue_size++;
        
        printf("[Main] Task submitted (queue size: %d)\n", queue_size);
        pthread_cond_signal(&queue_not_empty);
    } else {
        printf("[Main] Queue full! Task rejected.\n");
    }
    
    pthread_mutex_unlock(&queue_mutex);
}

// Worker thread function
void* worker_thread(void* arg) {
    int worker_id = *((int*)arg);
    printf("[Worker %d] Started and waiting for tasks...\n", worker_id);
    
    while (true) {
        pthread_mutex_lock(&queue_mutex);
        
        // Wait for tasks
        while (queue_size == 0 && !shutdown) {
            pthread_cond_wait(&queue_not_empty, &queue_mutex);
        }
        
        // Exit if shutdown and no more tasks
        if (shutdown && queue_size == 0) {
            pthread_mutex_unlock(&queue_mutex);
            break;
        }
        
        // Get task from queue
        Task task = task_queue[queue_front];
        queue_front = (queue_front + 1) % MAX_QUEUE_SIZE;
        queue_size--;
        
        pthread_mutex_unlock(&queue_mutex);
        
        // Execute task (outside lock to allow parallelism)
        task.function(task.argument);
    }
    
    printf("[Worker %d] Shutting down\n", worker_id);
    return NULL;
}

int main() {
    pthread_t threads[THREAD_POOL_SIZE];
    int thread_ids[THREAD_POOL_SIZE];
    
    printf("=== Thread Pool Demo ===\n");
    printf("Pool size: %d threads\n\n", THREAD_POOL_SIZE);
    
    // Create thread pool
    for (int i = 0; i < THREAD_POOL_SIZE; i++) {
        thread_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, worker_thread, &thread_ids[i]);
    }
    
    sleep(1);
    printf("\n--- Submitting Tasks ---\n");
    
    // Submit various tasks
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            submit_task(process_task, i);
        } else {
            submit_task(compute_task, i);
        }
        usleep(200000);  // 200ms delay between submissions
    }
    
    printf("\n--- All tasks submitted, waiting for completion ---\n\n");
    
    // Wait a bit for tasks to complete
    sleep(10);
    
    // Shutdown thread pool
    printf("\n--- Initiating shutdown ---\n");
    pthread_mutex_lock(&queue_mutex);
    shutdown = true;
    pthread_cond_broadcast(&queue_not_empty);
    pthread_mutex_unlock(&queue_mutex);
    
    // Wait for all workers to finish
    for (int i = 0; i < THREAD_POOL_SIZE; i++) {
        pthread_join(threads[i], NULL);
    }
    
    printf("\nThread pool shutdown complete!\n");
    
    pthread_mutex_destroy(&queue_mutex);
    pthread_cond_destroy(&queue_not_empty);
    
    return 0;
}

/*
 * THREAD POOL BENEFITS:
 * - Reuse threads (avoid creation/destruction overhead)
 * - Control resource usage (limit concurrent threads)
 * - Better performance for many small tasks
 * - Common pattern in web servers, task processors
 * 
 * EXERCISE:
 * 1. Compile: gcc -pthread 07_thread_pool.c -o thread_pool
 * 2. Observe how 4 workers handle 10 tasks
 * 3. Try increasing/decreasing THREAD_POOL_SIZE
 * 4. Submit more tasks (change loop limit)
 */
