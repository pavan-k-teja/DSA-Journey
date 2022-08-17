/* Dynamic Programming C++ implementation
of LIS problem  O(n^2) time */

#include <iostream>
#include <cstring>
// #include<bits/stdc++.h>
using namespace std;

int lis(int arr[], int n)
{
	int dp[n];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
    int lis_max=1;
	for (int i = 0; i < n; i++)
    {
		dp[i] = 1;
		for (int j = 0; j < i; j++)
			if (arr[j] < arr[i] && dp[j] + 1 > dp[i])
				dp[i] = dp[j] + 1;
        lis_max=max(lis_max, dp[i]);
	}

	// Return maximum value in lis[]
	return lis_max;
}


int main()
{
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("Length of lis is %d\n", lis(arr, n));

	return 0;
}
