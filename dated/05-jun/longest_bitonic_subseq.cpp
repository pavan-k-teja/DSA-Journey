/* Dynamic Programming C++ implementation
of LBS problem  O(n^2) time */

#include <iostream>
#include <cstring>
// #include<bits/stdc++.h>
using namespace std;

int lbs(int arr[], int n)
{
	int dp_lds[n];
	memset(dp_lds, 0, sizeof(dp_lds));

	dp_lds[n-1] = 1;
    
	for (int i = n-1; i>=0; i--)
    {
		dp_lds[i] = 1;
		for (int j = i+1; j < n; j++)
			if (arr[i] > arr[j] && dp_lds[i] < dp_lds[j] + 1 )
				dp_lds[i] = dp_lds[j] + 1;
	}

    int dp_lis[n];
	memset(dp_lis, 0, sizeof(dp_lis));
	dp_lis[0] = 1;
    
	for (int i = 0; i < n; i++)
    {
		dp_lis[i] = 1;
		for (int j = 0; j < i; j++)
			if (arr[j] < arr[i] && dp_lis[j] + 1 > dp_lis[i])
				dp_lis[i] = dp_lis[j] + 1;
	}

    int lbs_max=1;
    for(int i=0;i<n;i++)
    {
		cout<< (dp_lds[i] + dp_lis[i] -1) <<" ";
        lbs_max = max(lbs_max, (dp_lds[i] + dp_lis[i] -1));
	}

	return lbs_max;
}


int main()
{
	int arr[] = { 7, 8, 10, 2, 5, 7, 1, 4, 9, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("Length of lbs is %d\n", lbs(arr, n));

	return 0;
}
