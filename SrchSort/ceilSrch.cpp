
#include <bits/stdc++.h>
using namespace std;

int ceilSrch(int arr[], int lo, int hi, int target) // return index
{
    while(lo <= hi)
    {
        int mid = lo + (hi-lo)/2;
        if(arr[mid] == target)
            return mid;
        
    }

    return -1;
}