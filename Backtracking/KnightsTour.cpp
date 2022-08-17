#include<bits/stdc++.h>
using namespace std;

void printMat(vector<vector<int>> matrix)
{
    for(auto row : matrix)
    {
        for(auto ele : row)
            cout<<ele<<" ";
        cout<<"\n";
    }
}

void printAllSolutions(vector<vector<vector<int>>> &solutions)
{
    for(auto& matrix : solutions)
    {
        printMat(matrix);
        cout<<"\n\n";
    }
}

bool KnightsTour(vector<vector<int>> &matrix, int x, int y, int move_num)
{
    if(x<0 || x>=matrix.size() || y<0 || y>=matrix[0].size() || matrix[x][y]!=-1)
        return 0;
    
    matrix[x][y] = move_num;
    if(move_num == matrix.size()*matrix[0].size() - 1)
    {
        // printMat(matrix);
        return 1;
    }

    int sx[] = {-2, -1, +1, +2, +2, +1, -1, -2};
    int sy[] = {+1, +2, +2, +1, -1, -2, -2, -1};

    for(int i=0;i<8;i++)
        if(KnightsTour(matrix, x+sx[i], y+sy[i], move_num+1)==1)
            return 1;

    matrix[x][y] = -1;
    return 0;
}

void KnightsTourAll(vector<vector<int>> &matrix, int x, int y, int move_num, vector<vector<vector<int>>> &solutions)
{
    if(x<0 || x>=matrix.size() || y<0 || y>=matrix[0].size() || matrix[x][y]!=-1)
        return;
    
    matrix[x][y] = move_num;
    if(move_num == matrix.size()*matrix[0].size() - 1)
    {
        solutions.push_back(matrix);
        matrix[x][y] = -1; // this is necessary
        return;
    }

    int sx[] = {-2, -1, +1, +2, +2, +1, -1, -2};
    int sy[] = {+1, +2, +2, +1, -1, -2, -2, -1};

    for(int i=0;i<8;i++)
        KnightsTourAll(matrix, x+sx[i], y+sy[i], move_num+1, solutions);

    matrix[x][y] = -1;
    return;
}

int main()
{
    int row, col;
    cin>>row >>col;

    vector<vector<int>> matrix(row, vector<int> (col, -1));
    vector<vector<vector<int>>> solutions;
    int sx, sy;
    cin>>sx>>sy;

    KnightsTour(matrix, sx, sy, 0);
    printMat(matrix);
    // KnightsTourAll(matrix, sx, sy, 0, solutions);
    // printAllSolutions(solutions);
    cout<<"Total Solutions = "<< solutions.size();

    return 0;
}