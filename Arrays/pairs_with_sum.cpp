#include <bits/stdc++.h>
using namespace std;

int count_pairs1(int arr[], int n, int sum)
{
    unordered_map<int, bool> umap;
    for(int i=0;i<n;i++)
        umap[sum-arr[i]]++;

    int count=0;
    for(int i=0;i<n;i++)
    {
        if(umap.find(arr[i]) !=umap.end())
        {
            count++;
            if(sum==2*arr[i])
                count--;
        }
    }
    return count/2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);



    return 0;
}