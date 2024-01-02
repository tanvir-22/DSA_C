#include <stdio.h>
int partition(int a[],int low,int high){
    int pivot,i,j,temp;
    pivot = a[high];
    for(i=low-1,j=low;j<high;j++){
        if(a[j]<pivot){
            i+=1;
            temp = a[j];
            a[j] = a[i];
            a[i]= temp;
        }
    }
    temp = a[i+1];
    a[i+1] = a[high];
    a[high]= temp;
    return i+1;
}
void quick_sort(int a[],int low,int high){
    if(low>=high){
        return;
    }
    int p;
    p = partition(a,low,high);
    quick_sort(a,low,p-1);
    quick_sort(a,p+1,high);
}
int main(){
    int a[] = {6,3,8,4};
    int n = sizeof(a)/sizeof(a[0]);
    quick_sort(a,0,n-1);
    printf("sorted array: \n");
    for(int i=0;i<n;i++){
        printf("%d  ",a[i]);
    }
}