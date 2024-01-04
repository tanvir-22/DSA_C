#include<stdio.h>
void swap(int *n1,int *n2){
    int temp;
    temp = *(n1);
    *(n1) = *(n2);
    *(n2) = temp;
}
int main(){
    int num1=100;
    int num2 = 200;
    printf("\nbefore: num1 : %d  num2 : %d ",num1,num2);
    swap(&num1,&num2);
    printf("\nafter: num1 : %d  num2 : %d ",num1,num2);
}
