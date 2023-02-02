#include <bits/stdc++.h>
using namespace std;

vector<int> R, C, D1, D2;
bool canPlace(vector<string> &board, int x, int y, int n)
{
    // cout<<"in can place ";
    // cout<<R[x] + C[y] + D1[x+y] + D2[n - 1 + y-x];
    if (R[x] + C[y] + D1[x + y] + D2[n - 1 + y - x] != 0)
        return false;
    return true;
}

void place(vector<string> &board, int x, int y, int n)
{
    board[x][y] = 'Q';
    R[x] = 1, C[y] = 1, D1[x + y] = 1, D2[n - 1 + y - x] = 1;
}

void unplace(vector<string> &board, int x, int y, int n)
{
    board[x][y] = '.';
    R[x] = 0, C[y] = 0, D1[x + y] = 0, D2[n - 1 + y - x] = 0;
}

void solve(vector<vector<string>> &ans, vector<string> &board, int r, int n)
{
    if (r == n)
    {
        ans.push_back(board);
        return;
    }

    for (int j = 0; j < n; j++)
    {
        if (canPlace(board, r, j, n))
        {
            place(board, r, j, n);
            solve(ans, board, r + 1, n);
            unplace(board, r, j, n);
        }
    }
}

vector<vector<string>> solveNQueens(int A)
{
    R = C = vector<int>(A, 0);
    D1 = D2 = vector<int>(2 * A - 1, 0);

    vector<vector<string>> ans;
    vector<string> board(A, string(A, '.'));
    
    solve(ans, board, 0, A);
    return ans;
}

int main()
{

    return 0;
}