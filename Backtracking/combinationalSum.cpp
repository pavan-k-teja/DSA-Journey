#include <bits/stdc++.h>
using namespace std;


void helper(vector<int> &arr, int idx, int sum, vector<int> &curr, vector<vector<int>> &combinations)
{
    if(sum == 0)
    {
        combinations.push_back(curr);
        return;
    }
    if(idx >= arr.size() || sum<0)
        return;

    curr.push_back(arr[idx]);
    helper(arr, idx, sum-arr[idx], curr, combinations);
    curr.pop_back();

    helper(arr, idx+1, sum, curr, combinations);
    
}

vector<vector<int>> combinationSum(vector<int> &arr, int sum)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> combinations;
    vector<int> curr;
    helper(arr, 0, sum, curr, combinations);
    
    return combinations;
}

int main()
{
    vector<int> ar;
    ar.push_back(2);
    ar.push_back(4);
    ar.push_back(6);
    ar.push_back(8);
    int n = ar.size();
    int sum = 8;

    vector<vector<int>> res = combinationSum(ar, sum);
    
    for (int i = 0; i < res.size(); i++)
    {
        if (res[i].size() > 0)
        {
            cout << "( ";
            for (int j = 0; j < res[i].size(); j++)
                cout << res[i][j] << " ";
            cout << ") ";
        }
    }
}
