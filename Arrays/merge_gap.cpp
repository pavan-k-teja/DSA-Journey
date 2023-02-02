#include <bits/stdc++.h>
using namespace std;
void merge(int ar1[], int ar2[], int n, int m)
{
    int gap = ceil((n + m) / 2.0);
    while (gap > 0)
    {
        int i = 0;
        int j = gap;
        
        while (j < (n + m))
        {
            if (j < n && ar1[i] > ar1[j])
                swap(ar1[i], ar1[j]);
            
            else if (j >= n && i < n && ar1[i] > ar2[j - n])
                swap(ar1[i], ar2[j - n]);
            
            else if (j >= n && i >= n && ar2[i - n] > ar2[j - n])
                swap(ar2[i - n], ar2[j - n]);
            
            i++;
            j++;
        }

        if (gap == 1)
            gap = 0;
        else
            gap = ceil(gap / 2.0);
        
    }
}

int main()
{
    int arr1[] = {1, 4, 7, 8, 10};
    int arr2[] = {2, 3, 9};
    cout << "Before merge:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
    merge(arr1, arr2, 5, 3);
    cout << "After merge:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << arr2[i] << " ";
    }
}