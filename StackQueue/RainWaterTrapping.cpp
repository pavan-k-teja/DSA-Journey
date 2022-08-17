#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int maxWater(int arr[], int size)
{
    int maxLeft[size], maxRight[size];
    maxLeft[0]=arr[0];
    maxRight[size-1]=arr[size-1];

    for(int i=1;i<size;i++)
    {
        maxLeft[i]=max(maxLeft[i-1], arr[i]);
    }
    for(int i=size-2;i>=0;i--)
    {
        maxRight[i]=max(maxRight[i+1], arr[i]);
    }
    int sum=0;
    for(int i=0;i<size;i++)
    {
        sum+=(min(maxLeft[i], maxRight[i]) - arr[i]);
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
     
    cout << maxWater(arr, n);


    return 0;
}