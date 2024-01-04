#include<stdio.h>
#define stack_max 20

typedef struct{
    int top;
    int data[stack_max];
}stack;
void push(stack *s,int item){
    if(s->top>stack_max){
        printf("\nstack is full!");

    }
    else{
        s->data[s->top] = item;
        s->top+=1;
        printf("\nsuccessfully pushed into Stack");
    }

}
int pop(stack *s){
    int item;
    if(s->top==0){
            printf("\nstack is empty!");
        return -1;
    }
    else{

        s->top-=1;
        item = s->data[s->top];
    }
    return item;
}

int main(){
    stack mystack;
    int item;
    mystack.top =0;
    push(&mystack,50);
    push(&mystack,100);
    push(&mystack,150);
    item = pop(&mystack);
    printf("\nPoped item: %d ",item);
}
