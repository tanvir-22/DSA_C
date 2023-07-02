#include<stdio.h>
int binary_search(int array[],int n,int x)
{
    int left=0,right=n-1,mid;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(array[mid]==x)
        {
            return mid;
        }
        else if(array[mid]<x)
        {
            left=mid+1;
        }
        else
        {
            right=mid-1;
        }
    }
    return -1;
}
//complexity o(log2n)
int main()
{
    int array[]={11,12,13,14,15,16,17,18,19};
    
    int n=sizeof(array)/sizeof(array[0]);
    int x;
    printf("Enter a number in the array: ");
    scanf("%d",&x);
    int result=binary_search(array,n,x);
    if(result==-1)
    {
        printf("the number is not in the array: ");

    }
    else{
        printf("the number is in the index no: %d",result);
    }
    return 0;
}