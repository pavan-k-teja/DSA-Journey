//Stock span problem is same as nearest greater to left.
// ans[index]= index - ngl index

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> stockSpan(int arr[], int size)
{
    vector<int> v;
    stack<pair<int, int>> s;

    for (int i = 0; i < size; i++)
    {
        while (!s.empty() && s.top().first <= arr[i])
            s.pop();
        if (s.empty())
            v.push_back(i + 1);
        else
            v.push_back(i - s.top().second);

        s.push(make_pair(arr[i], i));
    }

    return v;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[] = {100, 80, 60, 70, 60, 75, 85};
    int size = sizeof(arr) / sizeof(arr[0]);
    vector<int> ans = stockSpan(arr, size);
    for (int i : ans)
        cout << i << " ";

    return 0;
}