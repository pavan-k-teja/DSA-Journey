#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        
        int dp[n+1];
        dp[1] = 1;
        int p2=1, p3=1, p5=1; //points to a position in dp arr;
        
        // _ 1 2 3 4 5 6 8
        for(int i=2;i<=n;i++)
        {
            int nxt_val2 = dp[p2] * 2;
            int nxt_val3 = dp[p3] * 3;
            int nxt_val5 = dp[p5] * 5;
            
            dp[i] = min(nxt_val2, min(nxt_val3, nxt_val5));
            
            if(dp[i]%2 == 0)
                p2++;
            if(dp[i]%3 == 0)
                p3++;
            if(dp[i]%5 == 0)
                p5++;   
        }
        
        return dp[n];
    }
};