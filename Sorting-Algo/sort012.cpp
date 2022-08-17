#include <bits/stdc++.h>
using namespace std;

int sort01(int arr[], int n)
{
    int low=0, high=n-1;
    while(low<high)
    {
        while(arr[low]==0 && low<high) low++;
        while(arr[high]==1) high--;

        if(low<high)
        {
            swap(arr[low], arr[high]);
            low++; high--;
        }
    }
}

int sort012(int arr[], int n)
{
    //0.....low mid......high......n-1
    // low points to first element of mid(1)
    // high points to the element before 2s 
    int low=0, mid=0, high=n-1;

    while(mid<=high)
    {
        if(arr[mid]==0)
        {
            swap(arr[low], arr[mid]);
            low++;mid++;
        }
        
        if(arr[mid]==1)
        {
            mid++;
        }
        
        if(arr[mid]==2)
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{


    return 0;
}