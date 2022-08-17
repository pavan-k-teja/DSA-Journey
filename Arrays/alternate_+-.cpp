#include <bits/stdc++.h>
using namespace std;

void sol(int arr[], int n)
{
    int i=0,j=1;
    while(i<n && j<n)
    {
        while (arr[i]<0 && i<n)
        {
            i+=2;
        }
        while (arr[j]>=0 && j<n)
        {
            j+=2;
        }
        if(i<n && j<n)
        {
            swap(arr[i], arr[j]);
            i+=2; j+=2;
        }
    }
    if(i>n && j>n) return;
    
    if(i>n)
    {
        i=n/2 *2 -1;
        while(j<i)
        {
            if(arr[j]<0 && arr[i]>=0)
            {
                swap(arr[i], arr[j]);
            }
            i-=2;j+=2;
        }
    }
    if(j>n)
    {
        j=(n&1)?n-1:n-2;
        while(i<j)
        {
            if(arr[j]<0 && arr[i]>=0)
            {
                swap(arr[i], arr[j]);
            }
            j-=2;i+=2;
        }
    }
    
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int arr[]={-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    int n=sizeof(arr)/sizeof(arr[0]);
    sol(arr,n);
    for(auto i:arr)
        cout<< i <<" ";

    return 0;
}