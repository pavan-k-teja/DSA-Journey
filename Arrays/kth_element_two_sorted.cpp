#include <bits/stdc++.h>
using namespace std;

float median(int arr1[], int arr2[], int m, int n)
{
    if (m > n)
        return median(arr2, arr1, n, m); 

    int low = 0, high = m, medianPos = ((m + n) + 1) / 2;
    
    while (low <= high)
    {
        int cut1 = (low + high) / 2;
        int cut2 = medianPos - cut1;

        int l1 = (cut1 == 0) ? INT_MIN : arr1[cut1 - 1];
        int l2 = (cut2 == 0) ? INT_MIN : arr2[cut2 - 1];
        int r1 = (cut1 == m) ? INT_MAX : arr1[cut1];
        int r2 = (cut2 == n) ? INT_MAX : arr2[cut2];

        if (l1 <= r2 && l2 <= r1)
        {
            if ((m + n) % 2 != 0)
                return max(l1, l2);
            else
                return (max(l1, l2) + min(r1, r2)) / 2.0;
        }

        else if (l1 > r2)
            high = cut1 - 1;

        else
            low = cut1 + 1;
    }
    return 0.0;
}

int kthelement(int arr1[], int arr2[], int m, int n, int k)
{
    if (m > n)
        return kthelement(arr2, arr1, n, m, k);

    int low = 0, high = m;

    while (low <= high)
    {
        int cut1 = (low + high) / 2;
        int cut2 = k - cut1;

        int l1 = (cut1 == 0) ? INT_MIN : arr1[cut1 - 1];
        int l2 = (cut2 == 0) ? INT_MIN : arr2[cut2 - 1];
        int r1 = (cut1 == n) ? INT_MAX : arr1[cut1];
        int r2 = (cut2 == m) ? INT_MAX : arr2[cut2];

        if (l1 <= r2 && l2 <= r1)
        {
            return max(l1, l2);



        }
        
        else if (l1 > r2)
            high = cut1 - 1;
        
        else
            low = cut1 + 1;     
    }
    return 1;
}

int main()
{
    int arr1[] = {1, 4, 7, 10, 12};
    int arr2[] = {2, 3, 6, 15};
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);
    cout << "The Median of two sorted arrays is " << fixed << setprecision(5)
         << median(arr1, arr2, m, n);
    return 0;
}