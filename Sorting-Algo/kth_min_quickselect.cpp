#include <bits/stdc++.h>
using namespace std;

int quickSelect(int a[], int start, int end, int k) // O(n)
{
    if (start > end)
        return -1;
    if (start == k - 1 && end == k - 1)
        return a[start];

    int pos = rand() % (end - start + 1) + start;
    swap(a[pos], a[end]);

    int index = start, pivot = end;
    for (int i = start; i < end; i++)
    {
        if (a[i] < a[pivot])
        {
            swap(a[i], a[index]);
            index++;
        }
    }
    
    swap(a[pivot], a[index]);
    if (k - 1 == index)
        return a[index];
    if (k - 1 < index)
        return quickSelect(a, start, index - 1, k);
        
    return quickSelect(a, index + 1, end, k);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // int n, k;
    // cin >> n >> k;
    // int a[n];
    // for (int i = 0; i < n; i++)
    //     cin >> a[i];
    int a[] = { 12, 3, 5, 7, 4, 19, 26 };
    int n = sizeof(a) / sizeof(a[0]), k = 3;

    int ans = quickSelect(a, 0, n - 1, k);
    cout << ans;

    return 0;
}