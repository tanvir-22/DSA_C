#include<stdio.h>
void selection_sort(int array[],int n)
{
    int i,j,index_min,temp;
    for(i=0;i<n-1;i++)
    {
        index_min=i;
        for(j=i+1;j<n;j++)
        {
            if(array[j]<array[index_min])
            {
                index_min=j;
            }
        }
        if(index_min!=j)
        {
            temp=array[i];
            array[i]=array[index_min];
            array[index_min]=temp;
        }
    }
    for(int k=0;k<n;k++)
    {
        printf("%2d",array[k]);
    }
}
//complexity O(n^2)
int main()
{
    int array[]={4,5,2,3,1};
    int n=sizeof(array)/sizeof(array[0]);
   selection_sort(array,n);

   return 0;
}