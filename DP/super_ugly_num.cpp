#include<bits/stdc++.h>
using namespace std;

int super_ugly_num(int n, int primes[], int k)
{
    int dp[n+1];
    dp[1]=1;
    priority_queue <vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    for(int i=0;i<k;i++)
        pq.push({primes[i], primes[i], 1}); // product, the prime, pointer to the dp_arr
    
    for(int i=2;i<=n;i++)
    {
        vector<int> mn = pq.top();
        pq.pop();
        if(dp[i-1]== mn[0])
            i--;
        dp[i] = mn[0];
        cout<<i<<" "<<dp[i]<<"\n";

        mn[2]++;
        mn[0] = (mn[1] * dp[mn[2]]);
        pq.push(mn);
    }


    return dp[n];
}

int main()
{
    int primes[] = {3, 5, 7, 11, 13};
    cout<< super_ugly_num(9, primes, 5);


    return 0;
}