#include <bits/stdc++.h>
using namespace std;

void fun(vector<int> &A, int start, int end, string soln)
{
    soln += to_string(A[start]) + " ";
    if (start == end - 1)
        return;
    for (int i = start + 1; i < end; i++)
    {
        cout << soln << A[i] << " ] ";
        fun(A, i, end, soln);
    }
}

vector<vector<int>> Solution::subsets(vector<int> &A)
{
    sort(A.begin(), A.end());
    cout << "[] ";
    for (int i = 0; i < A.size(); i++)
    {
        cout << "[" << A[i] << " ] ";
        fun(A, i, A.size(), "[");
    }
    vector<vector<int>> a;
    return a;
}

int main()
{

    return 0;
}