#include <stdio.h>
#define q_size 5
int head = 0, tail = 0;
void enq(int a[], int item)
{
    if ((tail + 1) % (q_size + 1) == head)
    {
        printf("\nQueue is full!");
        return;
    }
    a[tail] = item;
    tail = (tail + 1) % (q_size + 1);
}
int deq(int a[])
{
    int item;
    if (tail == head)
    {
        printf("\nQueue is Empty!");
        return -1;
    }
    item = a[head];
    head++;
    return item;
}
int main()
{
    int a[q_size + 1];
    int item;
    enq(a, 734);
    printf("\ntail: %d ", tail);
    enq(a, 333);
    printf("\ntail: %d ", tail);

    enq(a, 989);
    printf("\ntail: %d ", tail);
    item = deq(a);
    printf("\nitem: %d head: %d ", item, head);
}
