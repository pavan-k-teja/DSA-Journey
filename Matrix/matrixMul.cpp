#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> matrixMul(vector<vector<int>>& a, vector<vector<int>>& b)
{
    if(a.empty() || b.empty() || a[0].size() != b.size())
        return {};

    int row = a.size();
    int col = b[0].size();

    vector<vector<int>> ans(row, vector<int>(col, 0));

    for (int i = 0; i < row; i++) 
        for (int j = 0; j < col; j++)         
            for (int k = 0; k < a[0].size(); k++)
                ans[i][j] += a[i][k] * b[k][j];
            
        
    return ans;
}

int main()
{
    vector<vector<int>> a =
    {
        {10, 0, 0},
        {0, 1, 20}
    };

    vector<vector<int>> b =
    {
        {10, 1, 1, 1},
        {20, 1, 1, 1},
        {30, 2, 0, 30}
    };

    vector<vector<int>> ans = matrixMul(a, b);
    
    for(auto& row : ans)
    {
        for(auto& ele : row)
            cout<<ele<<" ";
        cout<<"\n";
    }

    return 0;
}