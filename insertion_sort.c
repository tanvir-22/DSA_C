#include<stdio.h>
void insertion_sort(int array[],int n)
{
    int temp,i,hole;
    for(i=1;i<n;i++)//we assume array[0]is sorted
    {
        temp=array[i];
        hole=i;
        while(hole>0 && array[hole-1]>temp)
        {
            array[hole]=array[hole-1];
            hole--;
        }
        array[hole]=temp;
    }
     printf("Sorted array: ");
    for(int k=0;k<n;k++)
    {
        printf("%2d",array[k]);
    }
}

//time complexity O(n^2)
//space complexity O(1)
int main()
{
    int array[]={9,7,6,4,2};
    int n=sizeof(array)/sizeof(array[0]);
    insertion_sort(array,n);
    return 0;
}