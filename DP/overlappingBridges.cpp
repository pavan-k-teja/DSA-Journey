// C++ implementation of building bridges
#include <bits/stdc++.h>

using namespace std;

// north-south coordinates
// of each City Pair
struct CityPairs
{
    int north, south;
};

// comparison function to sort on basis of north bank
bool compare(CityPairs &a, CityPairs &b)
{
    if (a.north == b.north)
        return a.south < b.south;
    return a.north < b.north;
}

int maxBridges(CityPairs values[], int n)
{
    sort(values, values+n, compare);

    int lis[n]={0};
    lis[0]=1;

    for(int i=1;i<n;i++)
    {
        int maxVal=0;
        for(int j=i-1;j>=0;j--)
        {
            if(values[j].south < values[i].south)
                maxVal = max(maxVal, lis[j]);
        }
        lis[i] = maxVal + 1;
    }

    int lisMax= 0;
    for(int i=0;i<n;i++)
        lisMax = max(lisMax, lis[i]);

    return lisMax;
}

// Driver program to test above
int main()
{
    CityPairs values[] = {{8, 1}, {1, 2}, {4, 3}, {3, 4}, {5, 5}, {2, 6}, {6, 7}, {7, 8}};
    int n = 8;
    cout << "Maximum number of bridges = "
         << maxBridges(values, n);
    return 0;
}
