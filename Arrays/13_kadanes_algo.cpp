#include <bits/stdc++.h>
using namespace std;

int kadanesAlg_n_cube(int a[], int n)
{
    int maxSum=INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum=0;
            for (int k = i; k < j; k++)
            {
                sum+=a[k];
            }
            maxSum=max(sum, maxSum);
        }
        
    }
    return maxSum;
}

int kadanesAlg_n_square(int a[], int n)
{
    int maxSum=INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int sum=0;
        for (int j = i; j < n; j++)
        {
            sum+=a[j];
        }
        maxSum=max(sum, maxSum);
        
    }
    return maxSum;
}

int kadanesAlg_v1(int a[], int n) //ok if u dont pick any
{
    int sum = 0, maxSum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        maxSum = max(maxSum, sum);
        if (sum < 0)
            sum = 0;
    }
    return maxSum;
}
int kadanesAlg_v2(int a[], int n) //must pick atleast one element
{
    int sum = 0, maxSum = a[0];
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        maxSum = max(maxSum, sum);
        if (sum < 0)
            sum = 0;
    }
    return maxSum;
}
void kadanesAlg_v3(int a[], int n)
{
    int maxSum = INT_MIN, sum = 0, curr_start = 0;
    int start, end;

    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (maxSum < sum)
        {
            maxSum = sum;
            start = curr_start;
            end = i;
        }
        if (sum < 0)
        {
            sum = 0;
            curr_start = i + 1;
        }
    }
    cout << "\nMaximum contiguous sum is " << maxSum << endl;
    cout << "Starting index " << start << "\nEnding index " << end ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3}; 
    int n = sizeof(a)/sizeof(a[0]); 
    // kadanesAlg_v3(a, n); 
    cout << kadanesAlg_v2(a, n); 

    return 0;
}