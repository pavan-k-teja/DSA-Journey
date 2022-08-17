#include<stdio.h>
#include<stdlib.h>

void dup1(int arr[], int n) // TC=O(n) SC=O(1)
{
    // cons
    // elements may be printed more than once
    // elements are not in order
    
    for(int i=0;i<n;i++)
    {
        if(arr[abs(arr[i])]<0)
            printf("%d ",arr[i]);
        else
            arr[abs(arr[i])] = -arr[abs(arr[i])];
    }
}

void dup2(int arr[], int n)
{
    for(int i=0;i<n;i++)
        arr[arr[i] % n] +=n;
    for(int i=0;i<n;i++)
        if(arr[i] >= 2*n)
            printf("%d ",i);
}

int main()
{
    int arr[]={ 19, 19, 1, 2, 3, 4, 5, 6, 7, 9, 8, 10, 11, 12, 13, 14, 15, 16, 17, 18};
    int n=sizeof(arr)/sizeof(arr[0]);
    dup2(arr,n);
    return 0;
}