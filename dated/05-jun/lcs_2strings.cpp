/* Dynamic Programming C++ implementation of LCS problem */
#include<bits/stdc++.h>
using namespace std;

int max(int a, int b);

int lcs( string X, string Y, int m, int n )
{
	int dp[m+1][n+1];
    memset(dp, 0, sizeof(dp));

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(X[i-1]==Y[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[m][n];
}

int lcs_v2( string X, string Y, int m, int n )
{// space used is O(n) only!!!

	int dp[2][n+1];
    memset(dp, 0, sizeof(dp));

    int idx; // takes only 0 or 1
    for(int i=1; i<=m; i++)
    {
        idx = i%2; // takes only 0 or 1
        for(int j=1;j<=n;j++)
        {
            if(X[i-1]==Y[j-1])
            {
                dp[idx][j] = 1 + dp[1-idx][j-1];
            }
            else
            {
                dp[idx][j] = max(dp[1-idx][j], dp[i][j-1]);
            }
        }
    }

    return dp[idx][n];
}


// Driver Code
int main()
{
	string X = "AGGTAB";
	string Y = "GXTXAYB";
	
	int m = X.size();
	int n = Y.size();
	
	cout << "Length of LCS is "
		<< lcs( X, Y, m, n );
	
	return 0;
}
