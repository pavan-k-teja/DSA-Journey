#include <iostream>
#include <utility>
#include <climits>
using namespace std;

void countSort(int arr[], int n, int exp)
{
	int output[n]; // output array
	int i, freq[10] = { 0 };

	// Store freq of occurrences in freq[]
	for (i = 0; i < n; i++)
		freq[(arr[i] / exp) % 10]++;

	// prefix sum
	for (i = 1; i < 10; i++)
		freq[i] += freq[i - 1];

	// Build the output array
	for (i = n - 1; i >= 0; i--)
    {
        int pos = --freq[(arr[i] / exp) %10];
        output[pos] = arr[i];
	}

	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

void radixsort(int arr[], int n)
{
	// Find the maximum number to know number of digits
	int mx = INT_MIN;
    for(int i=0;i<n;i++)
        mx = max(mx, arr[i]);
        
	for(int exp = 1; mx / exp > 0; exp *= 10)
		countSort(arr, n, exp);
}

// A utility function to print an array
void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

// Driver Code
int main()
{
	int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
	int n = sizeof(arr) / sizeof(arr[0]);
	
	// Function Call
	radixsort(arr, n);
	print(arr, n);
	return 0;
}
