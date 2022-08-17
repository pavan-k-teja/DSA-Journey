#include <bits/stdc++.h>

using namespace std;

void spread(vector<vector<int>> matrix, int r, int c, vector<vector<bool>> &vis)
{
    if(r<0 || r>= matrix.size() || c<0 || c>=matrix[0].size() || matrix[r][c] == 1 || vis[r][c] == true)
        return;

    vis[r][c] = true;

    spread(matrix, r, c-1, vis);
    spread(matrix, r-1, c, vis);
    spread(matrix, r, c+1, vis);
    spread(matrix, r+1, c, vis);
}


int countIslands(vector<vector<int>> matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();
    int count = 0;
    vector<vector<bool>> vis(row, vector<bool>(col, false));

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if(matrix[i][j]==0 && !vis[i][j])
            {
                spread(matrix, i, j, vis);
                count++;
            }
        }
    }

    return count;

}
/*
Test Case
8
8
0 0 1 1 1 1 1 1
0 0 1 1 1 1 1 1
1 1 1 1 1 1 1 0
1 1 0 0 0 1 1 0
1 1 1 1 0 1 1 0
1 1 1 1 0 1 1 0
1 1 1 1 1 1 1 0
1 1 1 1 1 1 1 0

*/

int main()
{
    int n, m;
    cin >> n;
    cin >> m;

    vector<vector<int>> matrix;

    for (int i = 0; i < n; i++)
    {
        vector<int> ans;
        for (int j = 0; j < m; j++)
        {
            int res;
            cin >> res;
            ans.push_back(res);
        }
        matrix.push_back(ans);
    }

    //write your code here
    cout<< countIslands(matrix);
}