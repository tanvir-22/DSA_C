#include<stdio.h>
void conquer(int a[],int si,int mid,int ei){
    int i,j;
    int temp[ei-si+1]; 
    int indx1 = si;
    int indx2 = mid+1;
    int x = 0;
    while(indx1<=mid&&indx2<=ei){
        if(a[indx1]<=a[indx2]){
            temp[x++] = a[indx1++];
        }
        else{
            temp[x++] = a[indx2++];
        }
    }
    while(indx1<=mid){
         temp[x++] = a[indx1++];
    }
    while (indx2<=ei)
    {
         temp[x++] = a[indx2++];
    }
    for(i=0,j=si;i<ei-si+1;i++,j++){
        a[j] = temp[i];
    }
}

void divide(int a[],int si,int ei){

if(si>=ei){
    return ;
}
int mid = si +(ei-si)/2;
divide(a,si,mid);
divide(a,mid+1,ei);
conquer(a,si,mid,ei);

}
int main(){
    int a[] = {6,3,8,4};
    int n = sizeof(a)/sizeof(a[0]);
    divide(a,0,n-1);
    printf("sorted array: \n");
    for(int i=0;i<n;i++){
        printf("%d  ",a[i]);
    }
}