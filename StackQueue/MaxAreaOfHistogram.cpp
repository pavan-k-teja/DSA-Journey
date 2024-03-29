#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int mah(int arr[], int size)
{
    vector<int> right;
    stack<pair<int, int>> s;

    for (int i = size - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top().first >= arr[i])
            s.pop();
        if (s.empty())
            right.push_back(i + 1);
        else
            right.push_back(s.top().second);

        s.push(make_pair(arr[i], i));
    }
    reverse(right.begin(), right.end());

    vector<int> left;
    while (!s.empty())
        s.pop();
    for (int i = 0; i < size; i++)
    {
        while (!s.empty() && s.top().first >= arr[i])
            s.pop();
        if (s.empty())
            left.push_back(-1);
        else
            left.push_back(s.top().second);

        s.push(make_pair(arr[i], i));
    }

    int maxArea = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        int width = right[i] - left[i] - 1;
        maxArea = max(maxArea, width * arr[i]);
    }
    return maxArea;
}

int largestRectangleArea(vector<int> &histo)
{
    stack<int> st;
    int maxA = 0;
    int n = histo.size();

    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() && (i == n || histo[st.top()] >= histo[i]))
        {
            int height = histo[st.top()];
            st.pop();

            int width = st.empty() ? i : (i - st.top() - 1);

            maxA = max(maxA, width * height);
        }

        st.push(i);
    }

    return maxA;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[] = {2, 1, 5, 6, 2, 3, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << mah(arr, size);

    return 0;
}