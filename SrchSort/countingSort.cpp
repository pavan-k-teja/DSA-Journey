#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void countSort(vector<int> &arr)
{
	int mx = INT_MIN;
	int mn = INT_MAX;
	for (int i : arr)
	{
		mx = max(mx, i);
		mn = min(mn, i);
	}
	int range = mx - mn + 1;

	vector<int> freq(range), output(arr.size());
	for (int i = 0; i < arr.size(); i++)
		freq[arr[i] - mn]++;

	// Below code is simple but not stable
	// int idx = 0;
	// for (int i = mn; i <= mx; i++)
	// {
	// 	for (int time = 0; time < freq[i - mn]; time++)
	// 	{
	// 		arr[idx] = i;
	// 		idx++;
	// 	}
	// }

	//prefix sum
	for(int i=1;i<range;i++)
		freq[i] = freq[i-1] + freq[i];

	for(int i=arr.size()-1; i>=0; i--)
	{
		int idx = --freq[arr[i]-mn];
		output[idx] = arr[i];
	}
	arr.swap(output);
}

void printArray(vector<int> &arr)
{
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << "\n";
}

int main()
{
	vector<int> arr = {-5, -1, 0, -3, 8, 5, -1, 5};
	countSort(arr);
	printArray(arr);
	return 0;
}
