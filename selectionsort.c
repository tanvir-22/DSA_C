#include<stdio.h>
void selection_sort(int array[],int n)
{
        int min,i,j,temp;
        for(i=0;i<n;i++)
        {   min=i; //we assume
            for(j=i+1;j<n;j++)
            {
                if(array[j]<array[min])
                {
                    min=j;
                }
            }
            if(min!=j)
            {
                temp=array[i];
                array[i]=array[min];
                array[min]=temp;
            }
        }
        printf("sorted array : ");
        for(int k=0;k<n;k++)
        {
            printf("%4d",array[k]);
        }
}
int main()
{
    int array[]={8,5,6,12,57};
    int n;
    n=sizeof(array)/sizeof(array[0]);
    selection_sort(array,n);
    return 0;
}