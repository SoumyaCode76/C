#include <stdio.h>
#include <stdlib.h>

typedef struct{
    unsigned int warning_id;
    unsigned int priority;
}Message_t;

typedef struct q{
    Message_t messages[100];
    unsigned int top;
    unsigned int bottom;
}Queue_t;

void init_data(void *data, int size){
    char *c = (char *)data;
    for(int i = 0; i < size; i++){
        c[i] = 0;
    }
}

void init_queue(Queue_t *q){
    init_data(q->messages, 100*sizeof(Message_t));
    q->top = 0;
    q->bottom = 0;
}

void enqueue(Queue_t *q, Message_t data){
    // Check if the queue is full
    if(check_full(q)){
        // Check if any lower priority message is in the queue
        int flag = 0;
        for(int i = q->top; i < q->bottom; i++){
            if(q->messages[i].priority < data.priority){
                q->messages[i] = data;
                flag = 1;
            }
        }
        if(flag == 0){
            // print queue is full
            printf("Queue is full\n");
            return;
        }
    }
    else{
        // print message is enqueued
        printf("Message is enqueued\n");
        q->messages[q->bottom] = data;
        q->bottom++;
    }
}

int dequeue(Queue_t *q, Message_t *data){
    // Check if the queue is empty
    if(check_empty(q)){
        // print queue is empty
        printf("Queue is empty\n");
        return -1;
    }
    data = q->messages[q->top];
    q->top++;
    return data;
}

int check_empty(Queue_t *q){
    if(q->top == q->bottom){
        return 1;
    }
    return 0;
}

int check_full(Queue_t *q){
    if(q->bottom == 100){
        return 1;
    }
    return 0;
}

int main(){
    Queue_t q;
    init_queue(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    while(!check_empty(&q)){
        printf("%d\n", dequeue(&q));
    }
    return 0;
}