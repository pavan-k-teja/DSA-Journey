#include <bits/stdc++.h>
using namespace std;

vector<int> slidingWindowMax(vector<int> &arr, int k)
{
    vector<int> ans;
    int n = arr.size();
    vector<int> ngr(n, -1);

    stack<int> s;
    s.push(n - 1);
    ngr[n - 1] = n;

    for (int i = n - 2; i >= 0; i--)
    {
        while (!s.empty() && arr[i] >= arr[s.top()])
            s.pop();

        if (s.empty())
            ngr[i] = n;
        else
            ngr[i] = s.top();

        s.push(i);
    }

    int i = 0;
    for (int w = 0; w <= n - k; w++)
    {
        if (i < w)
            i = w;

        while (ngr[i] < w + k)
            i = ngr[i];

        ans.push_back(arr[i]);
    }

    return ans;
}

vector<int> slidingWindowMax_v2(vector<int> &nums, int k)
{
    deque<int> dq;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        while (!dq.empty() && dq.front() <= i - k) // remove if front is out of bounds
            dq.pop_front();
            
        while (!dq.empty() && nums[dq.back()] < nums[i]) // remove if prev is smaller than curr
            dq.pop_back();

        dq.push_back(i);
        if (i >= k - 1) // window of size k is possible
            ans.push_back(nums[dq.front()]);
    }
    return ans;
}

int main()
{

    vector<int> arr = {7, 5, 2, 6, 4, 3, 8, 1, 5};
    vector<int> ans = slidingWindowMax_v2(arr, 4);

    for (auto &ele : ans)
    {
        cout << ele << " ";
    }
    return 0;
}