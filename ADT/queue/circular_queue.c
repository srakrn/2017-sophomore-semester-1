#include<stdio.h>
#define MAX_QUEUE 5

typedef struct queue_struct{
    char queue_list[MAX_QUEUE];
    int front, back, count;
} queue;

void initialise_queue(queue *qp){
    for(int i=0; i<MAX_QUEUE; i++){
        qp -> queue_list[i] = '\0';
    }
    qp -> front = 0;
    qp -> back = 0;
    qp -> count = 0;
}

void add_queue(queue *qp, char value){
    qp -> queue_list[qp -> back] = value;
    qp -> back += 1;
    qp -> back %= MAX_QUEUE;
    qp -> count++;
}

void remove_queue(queue *qp, char *value){
    *value = qp -> queue_list[qp -> front];
    qp -> queue_list[qp -> front] = '\0';
    qp -> front += 1;
    qp -> front %= MAX_QUEUE;
    qp -> count--;
}

void print_queue(queue *qp){
    for(int i=0; i<MAX_QUEUE; i++){
        if(qp -> queue_list[i] == '\0'){
            printf("( ) ");
        }
        else{
            printf("[%c] ",qp -> queue_list[i]);
        }
    }
    printf("\n");
    printf("Front = %d, Back = %d, Count = %d\n\n", qp -> front, qp -> back, qp -> count);
}

int main(){
    queue q;
    initialise_queue(&q);
    print_queue(&q);
    add_queue(&q, 'a');
    add_queue(&q, 'b');
    add_queue(&q, 'c');
    add_queue(&q, 'd');
    add_queue(&q, 'e');
    print_queue(&q);
    char c;
    remove_queue(&q, &c);
    print_queue(&q);
    printf("Removed queue = %c\n",c);
    add_queue(&q, 'f');
    print_queue(&q);
    return 0;
}
