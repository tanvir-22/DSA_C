#include<stdio.h>
#define stack_size 6
int top=0;
void push(int a[],int item)
{

    if(top<stack_size)
    {
        a[top] = item;
        top+=1;
        printf("\nsuccessfully added to stack:%d ",item);
    }
    else
    {
        printf("\nStack is full!");
    }
}
int pop(int a[])
{
    int item;
    if(top==0)
    {
        printf("\nStack is empty!");
        return -1;
    }
    else
    {
        top--;
        item = a[top];
        return item;
    }

}
int main()
{
    int a[stack_size];
    int item;
    push(a,500);
    push(a,100);
    push(a,900);
    item = pop(a);
    printf("\npoped item: %d ",item);
}
