#include<bits/stdc++.h>
using namespace std;


// Can p-painters each with work <=val complete arr??
bool check(int p, long long val, vector<int> &arr, int n)
{
    int painters_used=1;
    long long curr_painted= 0L;

    for(int i=0;i<n;i++)
    {
        if(arr[i] > val)
            return false;
        
        if(curr_painted + arr[i] > val)
        {
            painters_used++;
            curr_painted = (long long) arr[i];

            if(painters_used > p)
                return false;
        }
        else
            curr_painted += (long long) arr[i];
        
        curr_painted %= 10000003;
        
    }
    return true;
}

int paint(int p, int t, vector<int> &arr) 
{
    int n=arr.size();
    long long sum=0;
    long long lo=INT_MIN, hi;

    for(int i=0;i<n;i++)
    {
        sum+= (long long)arr[i];
        if(arr[i] > lo)
            lo = (long long) arr[i];
    }
    hi=sum;

    long long ans=sum;

    while(lo <= hi)
    {
        long long mid = lo + (hi-lo)/2;

        if(check(p, mid, arr, n))
        {
            ans=mid;
            hi=mid-1;
        }
        else
            lo=mid+1;
    }


    return (ans * (long long)t) % 10000003;
}



int main()
{

    

    return 0;
}