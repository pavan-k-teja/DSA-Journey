#include <bits/stdc++.h>
using namespace std;

int histArea(int arr[], int n)
{
    vector<int> right;
    right.reserve(n);
    stack<int> sr;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!sr.empty() && arr[sr.top()] >= arr[i])
            sr.pop();
        if (sr.empty())
            right.push_back(n);
        else
            right.push_back(sr.top());
        sr.push(i);
    }
    reverse(right.begin(), right.end());

    vector<int> left;
    left.reserve(n);
    stack<int> sl;

    for (int i = 0; i < n; i++)
    {
        while (!sl.empty() && arr[sl.top()] >= arr[i])
            sl.pop();
        if (sl.empty())
            left.push_back(-1);
        else
            left.push_back(sl.top());
        sl.push(i);
    }

    int mx = INT_MIN;
    for (int i = 0; i < n; i++)
        mx = max(mx, ((right[i] - left[i] - 1) * arr[i]));
    return mx;
}

template <int r, int c>
int maxBinRectArea(int (&mat)[r][c])
{
    int v[c];
    for (int j = 0; j < c; j++)
        v[j] = mat[0][j];
    int mx = histArea(v, c);

    for (int i = 1; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (mat[i][j] == 0)
                v[j] = 0;
            else
                v[j] += mat[i][j];
        }
        mx = max(mx, histArea(v, c));
    }
    return mx;
}

int main()
{
    int arr[] = {6, 2, 5, 4, 5, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    // cout<<histArea(arr,n)<<"\n";
    int ar[4][4] =
        {
            {0, 1, 1, 0},
            {0, 1, 1, 1},
            {1, 1, 1, 1},
            {1, 1, 0, 0}};

    cout << maxBinRectArea(ar);

    return 0;
}