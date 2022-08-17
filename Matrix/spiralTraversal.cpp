#include <bits/stdc++.h>
using namespace std;

void spiralTraversal(vector<vector<int>> &mat)
{
    int minrow = 0;
    int mincol = 0;
    int maxrow = mat.size() - 1;
    int maxcol = mat[0].size() - 1;

    int tne = mat.size() * mat[0].size(); // total numbers of elements
    int count = 0;

    while (count < tne)
    {
        // left wall
        for (int i = minrow; i <= maxrow && count < tne; i++)
        {
            cout << (mat[i][mincol]) << " ";
            count++;
        }

        mincol++;

        // bottom wall
        for (int i = mincol; i <= maxcol && count < tne; i++)
        {
            cout << (mat[maxrow][i]) << " ";
            count++;
        }

        maxrow--;

        // right wall
        for (int i = maxrow; i >= minrow && count < tne; i--)
        {
            cout << (mat[i][maxcol]) << " ";
            count++;
        }

        maxcol--;

        // top wall
        for (int i = maxcol; i >= mincol && count < tne; i--)
        {
            cout << (mat[minrow][i]) << " ";
            count++;
        }

        minrow++;
    }
}

int main()
{
    vector<vector<int>> mat =
        {
            {1, 2, 3, 4, 5, 6},
            {7, 8, 9, 10, 11, 12},
            {13, 14, 15, 16, 17, 18}};

    spiralTraversal(mat);
    // expected output: 1 7 13 14 15 16 17 18 12 6 5 4 3 2 8 9 10 11

    return 0;
}