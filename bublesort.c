#include<stdio.h>

int main()
{
    int array[]={7,4,6,2,9};
    int temp,i,j,n;
    n=sizeof(array)/sizeof(array[0]);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(array[j]>array[j+1])
            {
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
    printf("sorted array: ");
    for(int k=0;k<n;k++)
    {
        printf("%3d",array[k]);
    }
    return 0;
}