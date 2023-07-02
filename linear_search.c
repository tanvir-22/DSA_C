#include<stdio.h>
int linear_search(int array[],int n,int x)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        if(array[i]==x)
        {
            return i;
        }
    }
    return -1;
}
//time complexity=O(n)
//space complexity=O(1)
int main()
{
    int m;
    printf("enter a number : ");
    scanf("%d",&m);
    int array[]={1,2,3,4,5,8,9,0};
    int n=sizeof(array)/sizeof(array[0]);
    int result=linear_search(array,n,m);
    if(result==-1)
    {
        printf("value is not present in  the array!");
    }
    else{
        printf("value present at index no-%d",result);

    }
    return 0;
}