/*
 * LESSON 8: Common Interview Problems
 * 
 * This file contains solutions to common threading interview questions
 */

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

/* ========================================
 * PROBLEM 1: Print Numbers in Sequence with Multiple Threads
 * ======================================== */

pthread_mutex_t print_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t print_cond = PTHREAD_COND_INITIALIZER;
int current_thread = 0;

void* print_sequence(void* arg) {
    int thread_id = *((int*)arg);
    
    for (int i = thread_id; i <= 30; i += 3) {
        pthread_mutex_lock(&print_mutex);
        
        // Wait until it's this thread's turn
        while (current_thread != thread_id) {
            pthread_cond_wait(&print_cond, &print_mutex);
        }
        
        printf("Thread %d: %d\n", thread_id, i);
        
        // Next thread's turn
        current_thread = (current_thread + 1) % 3;
        pthread_cond_broadcast(&print_cond);
        
        pthread_mutex_unlock(&print_mutex);
    }
    
    return NULL;
}

void problem1_print_sequence() {
    printf("\n=== PROBLEM 1: Print 1-30 with 3 threads in sequence ===\n");
    pthread_t threads[3];
    int ids[3] = {0, 1, 2};
    
    for (int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, print_sequence, &ids[i]);
    }
    
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }
}

/* ========================================
 * PROBLEM 2: Implement Read-Write Lock
 * ======================================== */

typedef struct {
    pthread_mutex_t mutex;
    pthread_cond_t read_cond;
    pthread_cond_t write_cond;
    int readers;
    int writers;
    int waiting_writers;
} rwlock_t;

void rwlock_init(rwlock_t* rw) {
    pthread_mutex_init(&rw->mutex, NULL);
    pthread_cond_init(&rw->read_cond, NULL);
    pthread_cond_init(&rw->write_cond, NULL);
    rw->readers = 0;
    rw->writers = 0;
    rw->waiting_writers = 0;
}

void read_lock(rwlock_t* rw) {
    pthread_mutex_lock(&rw->mutex);
    
    // Wait if there's a writer or waiting writers
    while (rw->writers > 0 || rw->waiting_writers > 0) {
        pthread_cond_wait(&rw->read_cond, &rw->mutex);
    }
    
    rw->readers++;
    pthread_mutex_unlock(&rw->mutex);
}

void read_unlock(rwlock_t* rw) {
    pthread_mutex_lock(&rw->mutex);
    rw->readers--;
    
    // If last reader, wake up waiting writers
    if (rw->readers == 0) {
        pthread_cond_signal(&rw->write_cond);
    }
    
    pthread_mutex_unlock(&rw->mutex);
}

void write_lock(rwlock_t* rw) {
    pthread_mutex_lock(&rw->mutex);
    rw->waiting_writers++;
    
    // Wait while there are readers or another writer
    while (rw->readers > 0 || rw->writers > 0) {
        pthread_cond_wait(&rw->write_cond, &rw->mutex);
    }
    
    rw->waiting_writers--;
    rw->writers++;
    pthread_mutex_unlock(&rw->mutex);
}

void write_unlock(rwlock_t* rw) {
    pthread_mutex_lock(&rw->mutex);
    rw->writers--;
    
    // Wake up all waiting readers and one writer
    pthread_cond_broadcast(&rw->read_cond);
    pthread_cond_signal(&rw->write_cond);
    
    pthread_mutex_unlock(&rw->mutex);
}

int shared_data = 0;
rwlock_t rwlock;

void* reader_thread(void* arg) {
    int id = *((int*)arg);
    
    for (int i = 0; i < 3; i++) {
        read_lock(&rwlock);
        printf("  Reader %d: Read value = %d\n", id, shared_data);
        sleep(1);
        read_unlock(&rwlock);
        sleep(1);
    }
    
    return NULL;
}

void* writer_thread(void* arg) {
    int id = *((int*)arg);
    
    for (int i = 0; i < 2; i++) {
        write_lock(&rwlock);
        shared_data++;
        printf("  Writer %d: Wrote value = %d\n", id, shared_data);
        sleep(2);
        write_unlock(&rwlock);
        sleep(1);
    }
    
    return NULL;
}

void problem2_rwlock() {
    printf("\n=== PROBLEM 2: Read-Write Lock ===\n");
    pthread_t readers[3], writers[2];
    int reader_ids[3] = {1, 2, 3};
    int writer_ids[2] = {1, 2};
    
    rwlock_init(&rwlock);
    
    // Create readers and writers
    for (int i = 0; i < 3; i++) {
        pthread_create(&readers[i], NULL, reader_thread, &reader_ids[i]);
    }
    for (int i = 0; i < 2; i++) {
        pthread_create(&writers[i], NULL, writer_thread, &writer_ids[i]);
    }
    
    // Join all
    for (int i = 0; i < 3; i++) {
        pthread_join(readers[i], NULL);
    }
    for (int i = 0; i < 2; i++) {
        pthread_join(writers[i], NULL);
    }
    
    printf("Final shared_data value: %d\n", shared_data);
}

/* ========================================
 * PROBLEM 3: Barrier Synchronization
 * ======================================== */

#define NUM_BARRIER_THREADS 5

pthread_mutex_t barrier_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t barrier_cond = PTHREAD_COND_INITIALIZER;
int barrier_count = 0;

void barrier_wait(int total_threads) {
    pthread_mutex_lock(&barrier_mutex);
    
    barrier_count++;
    
    if (barrier_count == total_threads) {
        // Last thread arrived - wake everyone
        barrier_count = 0;
        pthread_cond_broadcast(&barrier_cond);
    } else {
        // Wait for others
        pthread_cond_wait(&barrier_cond, &barrier_mutex);
    }
    
    pthread_mutex_unlock(&barrier_mutex);
}

void* barrier_thread(void* arg) {
    int id = *((int*)arg);
    
    printf("Thread %d: Phase 1 - Doing some work...\n", id);
    sleep(id);  // Different work times
    
    printf("Thread %d: Reached barrier\n", id);
    barrier_wait(NUM_BARRIER_THREADS);
    
    printf("Thread %d: Phase 2 - Continuing after barrier\n", id);
    
    return NULL;
}

void problem3_barrier() {
    printf("\n=== PROBLEM 3: Barrier Synchronization ===\n");
    printf("All threads must reach barrier before continuing\n\n");
    
    pthread_t threads[NUM_BARRIER_THREADS];
    int ids[NUM_BARRIER_THREADS];
    
    for (int i = 0; i < NUM_BARRIER_THREADS; i++) {
        ids[i] = i + 1;
        pthread_create(&threads[i], NULL, barrier_thread, &ids[i]);
    }
    
    for (int i = 0; i < NUM_BARRIER_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    printf("\nAll threads completed!\n");
}

/* ========================================
 * MAIN - Run all problems
 * ======================================== */

int main() {
    printf("=== MULTITHREADING INTERVIEW PROBLEMS ===\n");
    printf("\nThese are common problems asked in technical interviews.\n");
    printf("Study the implementations carefully!\n");
    
    problem1_print_sequence();
    
    sleep(2);
    problem2_rwlock();
    
    sleep(2);
    problem3_barrier();
    
    return 0;
}

/*
 * COMMON INTERVIEW QUESTIONS TO PREPARE:
 * 
 * 1. What is a race condition? How do you prevent it?
 *    → Multiple threads accessing shared data, use mutex
 * 
 * 2. What is deadlock? How to prevent?
 *    → Circular wait for locks, use lock ordering
 * 
 * 3. Mutex vs Semaphore?
 *    → Mutex: binary, ownership; Semaphore: counting, no ownership
 * 
 * 4. What is a condition variable?
 *    → Signal between threads when condition changes
 * 
 * 5. Difference between thread and process?
 *    → Thread: shares memory; Process: separate memory
 * 
 * 6. What is thread pool? Why use it?
 *    → Reusable threads, avoid overhead, control resources
 * 
 * 7. Producer-Consumer problem?
 *    → Use mutex + condition variables (see Lesson 5)
 * 
 * COMPILE:
 * gcc -pthread 08_interview_questions.c -o interview_questions
 */
