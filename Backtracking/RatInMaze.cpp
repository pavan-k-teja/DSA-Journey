#include<bits/stdc++.h>
using namespace std;

void printPath(string path)
{
    for(auto c : path)
    {
        cout<<c;
    }
    cout<<"\n";
}

void printAllSolutions(vector<string> &solutions)
{
    for(string& sol : solutions)
    {
        printPath(sol);
        // cout<<"\n";
    }
}

bool RatInMaze(vector<vector<int>> &matrix, int x, int y, string &path)
{
    if(x<0 || x>=matrix.size() || y<0 || y>=matrix[0].size() || matrix[x][y]!=1)
        return 0;
    
    if(x==matrix.size()-1 && y==matrix.size()-1)
    {
        printPath(path);
        return 1;
    }
    matrix[x][y] = 2;

    int dx[] = {+1, 0, 0, -1};
    int dy[] = {0, -1, +1, 0};
    string dir = "DLRU";

    for(int i=0;i<4;i++)
    {
        path+=dir[i];
        if(RatInMaze(matrix, x+dx[i], y+dy[i], path)==1)
            return 1;
        path.pop_back();
    }

    matrix[x][y] = 1;
    
    return 0;
}

void RatInMazeAll(vector<vector<int>> &matrix, int x, int y, string &path, vector<string> &paths)
{
    if(x<0 || x>=matrix.size() || y<0 || y>=matrix[0].size() || matrix[x][y]!=1)
        return;
    
    if(x==matrix.size()-1 && y==matrix.size()-1)
    {
        paths.push_back(path);
        return;
    }
    matrix[x][y] = 2;

    int dx[] = {+1, 0, 0, -1};
    int dy[] = {0, -1, +1, 0};
    string dir = "DLRU";

    for(int i=0;i<4;i++) // we will send the semi-processed move
    {
        path+=dir[i];
        RatInMazeAll(matrix, x+dx[i], y+dy[i], path, paths);
        path.pop_back();
    }

    matrix[x][y] = 1;
    return;
}

int main()
{
    vector<vector<int>> matrix
    {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    // vector<vector<vector<int>>> solutions;
    // int sx, sy;
    // cin>>sx>>sy;
    string path;
    vector<string> paths;
    // RatInMaze(matrix, 0, 0, path);
    RatInMazeAll(matrix, 0, 0, path, paths);
    printAllSolutions(paths);
    cout<<"Total Solutions = "<< paths.size();

    return 0;
}