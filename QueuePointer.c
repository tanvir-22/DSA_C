#include<stdio.h>
#define q_size 5

typedef struct
{
    int head,tail;
    int data[q_size+1];
} queue;

void enq(queue *q,int item)
{
    if((q->tail+1)%(q_size+1)==q->head){
        printf("\nqueue is full!");
        return;
    }
    q->data[q->tail] = item;
    q->tail = (q->tail+1)%(q_size+1);
}
int deq(queue *q)
{
    int item;
    if(q->head==q->tail){
        printf("\nQueue is Empty!");
        return -1;
    }
    item = q->data[q->head];
    q->head = (q->head+1)%(q_size+1);
    return item;
}
int main()
{
    queue myq;
    myq.head =0;
    myq.tail = 0;
    enq(&myq,780);
    printf("\ntail: %d ",myq.tail);
    enq(&myq,850);
       printf("\ntail: %d ",myq.tail);
       enq(&myq,1900);
          printf("\ntail: %d ",myq.tail);
    printf("\nbegining head: %d ",myq.head);
    int item;
    item = deq(&myq);
    printf("\nitem: %d head: %d ",item,myq.head);


}
