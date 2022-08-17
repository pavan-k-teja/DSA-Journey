#include<bits/stdc++.h>
using namespace std;

void printMat(vector<vector<int>> matrix)
{
    for(auto row : matrix)
    {
        for(auto ele : row)
        {
            cout<<ele<<" ";
        }
        cout<<"\n";
    }
}

bool isValid(vector<vector<int>> &grid, int cx, int cy, int val)
{
    int r=grid.size();
    int c = grid[0].size();

    for(int i=0;i<r;i++)
        if(cx!=i && grid[i][cy] == val)
            return false;
    
    for(int i=0;i<c;i++)
        if(cy!=i && grid[cx][i] == val)
            return false;

    int boxX=cx/3;
    int boxY=cy/3;

    for(int i=(boxX*3);i<(boxX*4);i++)
    {
        for(int j=(boxY*3);j<(boxY*4);j++)
        {
            if((cx!=i || cy!=j) && grid[i][j] == val)
                return false;
        }
    }

    return true;
}

bool sudoku(vector<vector<int>> &grid, int cx, int cy)
{
    int r=grid.size();
    int c = grid[0].size();
    
    if(cy==c)
    {
        cx++;
        cy=0;
    }
    if(cx==r)
        return true;

    if(grid[cx][cy] > 0)
        return sudoku(grid, cx, cy+1);
    

    for(int i=1;i<=9;i++)
    {
        if(!isValid(grid, cx, cy, i))
            continue;
        
        grid[cx][cy]=i;

        if(sudoku(grid, cx, cy+1) == true)
            return true;
        
        grid[cx][cy]=0;
        
    }

    return false;
}

int main()
{

    vector<vector<int>> grid =
    { 
        { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
        { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
        { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
        { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
        { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
        { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
        { 0, 0, 5, 2, 0, 6, 3, 0, 0 } 
    };

    bool isPos = sudoku(grid, 0, 0);
    // printMat(grid);
    if(isPos)
    {
        printMat(grid);
    }
    else
        cout<<"Not Possible \n";

    return 0;
}