#include <bits/stdc++.h>
using namespace std;

void findMedian(vector<int> arr, int n)
{
    priority_queue<int> lower;
    priority_queue<int, vector<int>, greater<int>> upper;

    for (int i = 0; i < n; i++)
    {
        upper.push(arr[i]);
        lower.push(upper.top());
        upper.pop();

        if (lower.size() > upper.size())
        {
            upper.push(lower.top());
            lower.pop();
        }

        if (upper.size() > lower.size())
            cout << upper.top();
        else
            cout << (upper.top() + lower.top()) / 2;
        cout << " ";
    }
}