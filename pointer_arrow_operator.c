#include<stdio.h>
 struct student {
    int roll_no;
    char name[20];
    int mark;
 };

 struct student s={100,"shafin",4000};
 int main(){
    struct student *ptr=&s;
    printf("the name is: %s",ptr->name);//(*ptr).name
    printf("\nthe roll is: %d",(*ptr).roll_no);
    printf("\nthe mark is: %d",s.mark);
 }
