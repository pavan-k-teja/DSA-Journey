#include<bits/stdc++.h>
using namespace std;


int LPS(string s)
{
    int n = s.size();
    int dp[n][n];
    memset(dp, 0, sizeof(dp));

    // basic traversal. cme from behind
    // for(int i=n-1;i>=0;i--)
    // {
    //     for(int j=i;j<n;j++)
    //     {
    //         if(i==j)
    //             dp[i][j] = 1;
    //         else if(s[i]==s[j])
    //             dp[i][j] = 2 + dp[i+1][j-1];
    //         else
    //             dp[i][j]=max(dp[i][j-1], dp[i+1][j]);
    //     }
    // }

    for(int diag=0; diag<n; diag++) // iterating diags of upper triangle only
    {
        for(int i=0, j=diag; j<n; i++, j++)
        {
            if(diag==0)
                dp[i][j] = 1;
            else if(s[i]==s[j])
                dp[i][j] = 2 + dp[i+1][j-1];
            else
                dp[i][j]=max(dp[i][j-1], dp[i+1][j]);
        }

    }

    return dp[0][n-1];
}

int main()
{

    string s;
    cin>>s;
    cout<< LPS(s);

    return 0;
}