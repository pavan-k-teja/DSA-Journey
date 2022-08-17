//Leetcode-264
class Solution {
public:

    int nthUglyNumber(int n) {
        vector<int> dp(n,0);
        dp[0] = 1;
        int two_pointer = 0,three_pointer = 0,five_pointer = 0;
        
        for(int i=1;i<n;++i)
        {
            dp[i] = min({2*dp[two_pointer], 3*dp[three_pointer], 5*dp[five_pointer]});
            
            if(dp[i] % 2 == 0)
                two_pointer++;
            if(dp[i] % 3 == 0)
                three_pointer++;
            if(dp[i] % 5 == 0)
                five_pointer++;
        }
        return dp[n-1];
    }

};