#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> nsr(int arr[], int size)
{
    vector<int> v;
    stack<int> s;

    for (int i = size - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() >= arr[i])
            s.pop();
        if (s.empty())
            v.push_back(-1);
        else
            v.push_back(s.top());

        s.push(arr[i]);
    }
    std::reverse(v.begin(), v.end());
    return v;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[] = {17, 18, 5, 4, 6, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    vector<int> ans = nsr(arr, size);
    for (int i : ans)
        cout << i << " ";
    return 0;
}