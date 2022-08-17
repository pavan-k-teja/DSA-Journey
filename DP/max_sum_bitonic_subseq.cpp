#include<bits/stdc++.h>
using namespace std;

// Longest Increasing Subsequence
// changed to max sum incr sub ending with the index
vector<int> LIS(int arr[], int n)
{
    vector<int> lis(n);
    lis[0]=arr[0];

    for(int i=1;i<n;i++)
    {
        int maxSum=0;
        for(int j=0;j<i;j++)
        {
            if(arr[j] < arr[i] && lis[j] > maxSum)
            {
                maxSum=lis[j];
            }
        }
        lis[i] = maxSum+arr[i];
    }

    return lis;
}

vector<int> LDS(int arr[], int n)
{
    vector<int> lds(n);
    lds[n-1]=arr[n-1];

    for(int i=n-2;i>=0;i--)
    {
        int maxSum=0;
        for(int j=n-1;j>i;j--)
        {
            if(arr[i] > arr[j] && lds[j] > maxSum)
            {
                maxSum=lds[j];
            }
        }
        lds[i] = maxSum+arr[i];
    }

    return lds;
}


int maxSumBitonic(int arr[], int n)
{
    vector<int> lis = LIS(arr, n);
    vector<int> lds = LDS(arr, n);

    int maxSum=0;
    for(int i=0;i<lis.size();i++)
    {
        maxSum=max(maxSum, lis[i] + lds[i] - arr[i]);
    }

    return maxSum;
}

int main()
{
    int arr[] = {80, 60, 30, 40, 20, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<< maxSumBitonic(arr, n);

    return 0;
}