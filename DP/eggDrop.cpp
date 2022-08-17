#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:

    int eggDrop(int eggs, int floors) 
    {
        // your code here
        int dp[eggs+1][floors+1];
        
        for(int e=1;e<=eggs;e++)
        {
            for(int f=0; f<=floors; f++)
            {
                if(f==0)
                    dp[e][f]=0;
                else if(e==1)
                    dp[e][f]=f;
                
                else
                {
                    int minCost=INT_MAX;
                    for(int x=1;x<=f;x++)
                    {
                        int breaks = dp[e-1][x-1];
                        int survives = dp[e][f-x];
                        minCost = min(minCost, max(breaks, survives)+1);
                    }
                    dp[e][f]=minCost;
                }
            }
        }
        return dp[eggs][floors];
    }
};

int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int eggs, floors;
        cin>>eggs>>floors;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(eggs, floors)<<endl;
    }
    return 0;
}