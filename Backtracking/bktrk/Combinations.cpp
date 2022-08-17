#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &ret, vector<int> &tmp, int n, int left, int k)
{
    if (k == 0)
    {
        ret.push_back(tmp);
        return;
    }
    for (int i = left; i <= n; ++i)
    {
        tmp.push_back(i);
        dfs(ret, tmp, n, i + 1, k - 1);
        tmp.pop_back();
    }
}

vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> ret;
    vector<int> tmp;
    dfs(ret, tmp, n, 1, k);
    return ret;
}

int main()
{

    return 0;
}