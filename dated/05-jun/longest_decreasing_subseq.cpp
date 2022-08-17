/* Dynamic Programming C++ implementation
of LDS problem  O(n^2) time */

#include <iostream>
#include <cstring>
// #include<bits/stdc++.h>
using namespace std;

int lds(int arr[], int n)
{
	int dp[n];
	memset(dp, 0, sizeof(dp));
	dp[n-1] = 1;
    int lds_max=1;
	for (int i = n-1; i>=0; i--)
    {
		dp[i] = 1;
		for (int j = i+1; j < n; j++)
			if (arr[i] > arr[j] && dp[i] < dp[j] + 1 )
				dp[i] = dp[j] + 1;
        lds_max=max(lds_max, dp[i]);
	}
    // for(int i=0;i<n;i++)
    //     cout<<dp[i]<<" ";

	// Return maximum value in lds[]
	return lds_max;
}


int main()
{
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60, 80, 3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("Length of lds is %d\n", lds(arr, n));

	return 0;
}
