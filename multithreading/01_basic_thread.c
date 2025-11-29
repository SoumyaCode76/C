/*
 * LESSON 1: Creating Your First Thread
 * 
 * Concepts covered:
 * - pthread_create(): Creates a new thread
 * - pthread_join(): Waits for a thread to finish
 * - Basic thread function signature
 */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_THREADS 5

volatile bool stop_threads = false;

typedef struct {
    int val;
    bool locked;
}Obj_t;

typedef struct {
    int retval;
    void * addr;
    int val;
} Args_t;

Obj_t * rwlock_init(){
    static Obj_t rwlock;
    rwlock.val = 0;
    rwlock.locked = false;
    return &rwlock;
}

Args_t * create_args(int retval, void * addr, int val){
    static Args_t args_storage;
    args_storage.retval = retval;
    args_storage.addr = (void *)addr;
    args_storage.val = val;
    return &args_storage;
}

// Thread function - must return void* and take void* as parameter
void* print_message(void* arg) {
    char* message = (char*)arg;
    
    for (int i = 0; i < 5; i++) {
        printf("%s (iteration %d)\n", message, i + 1);
        sleep(1);  // Sleep for 1 second
    }
    return NULL;
}

void * write_to_address(void * arg){
    /* Design 
        * arg[0] = return value
        * arg[1] = address to write to
        * arg[2] = value to write
    */
   Args_t * args = (Args_t *) arg;
   Obj_t * rwlock = (Obj_t *) args->addr;
   while(stop_threads == false)
   {
    //    printf("Attempting to write value %d to address %p\n", args->val, args->addr);
        if(rwlock->locked == false){
            rwlock->locked = true;
            rwlock->val = args->val;
            args->val++;
            sleep(5);
            printf("Wrote value %d to address %p\n", args->val, args->addr);       
            args->retval = 0;
            rwlock->locked = false;
        } else {
            // printf("Could not acquire lock to write value %d to address %p\n", args->val, args->addr);
            args->retval = -1;
        }
    }
    return NULL;
}

void * read_from_address(void * arg){
    /* Design
        * arg[0] = return value
        * arg[1] = address to read from
        * arg[2] = buffer to store read value
        * print the value read
    */
    Args_t * args = (Args_t *) arg;
    Obj_t * rwlock = (Obj_t *) args->addr;
    while(stop_threads == false)
    {   
    if(rwlock->locked == false){
        rwlock->locked = true;
        int value = rwlock->val;
        args->retval = value;
        printf("Read value %d from address %p\n", value, args->addr);
        sleep(2);        
        rwlock->locked = false;
    } else {
        args->retval = -1;
    }
    }
    return NULL;
}

int main() {

    Obj_t * rwlock = rwlock_init();
    pthread_t thread_id[MAX_THREADS] = {0UL};
    char* message = "Hello from thread!";
    
    printf("Main: Creating thread...\n");
    Args_t * args = create_args(0, (void*)rwlock, 42);

    // Create a new thread
    // pthread_create(thread_id, attributes, function, argument)
    if (pthread_create(&thread_id[0], NULL, print_message, (void*)message) != 0) {
        perror("Failed to create thread");
        return 1;
    }
    if(pthread_create(&thread_id[1], NULL, write_to_address, (void*)args) != 0){
        perror("Failed to create thread");
        return 1;
    }
    if(pthread_create(&thread_id[2], NULL, read_from_address, (void*)args) != 0){
        perror("Failed to create thread");
        return 1;
    }
    printf("Main: Thread created successfully!\n");
    
    // Main thread continues executing
    for (int i = 0; i < 50; i++) {
        printf("Main thread working... (iteration %d)\n", i + 1);
        sleep(1);
    }
    stop_threads = true;
    // Wait for the thread to finish
    printf("Main: Waiting for thread to finish...\n");
    pthread_join(thread_id[0], NULL);
    pthread_join(thread_id[1], NULL);
    
    printf("Main: Thread finished. Exiting.\n");
    return 0;
}

/*
 * EXERCISE:
 * 1. Compile: gcc -pthread 01_basic_thread.c -o basic_thread
 * 2. Run and observe how both threads run concurrently
 * 3. Try creating 2-3 threads with different messages
 * 4. Experiment with different sleep durations
 */
