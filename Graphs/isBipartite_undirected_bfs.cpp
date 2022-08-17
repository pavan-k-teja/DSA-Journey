#include <bits/stdc++.h>
using namespace std;

bool is_comp_bipartite(int node, int V, vector<int> adjList[], vector<int> &color)
{
    queue<int> q;
    q.push(node);
    color[node] = 0;

    while(!q.empty())
    {
        int n = q.front();
        q.pop();

        for(int neigh : adjList[n])
        {
            if(color[neigh] == -1)
            {
                color[neigh] = 1 - color[n];
                q.push(neigh);
            }
            else if(color[neigh] == color[n])
                return false;
        }
    }

    return true;
}

bool isBipartite(int V, vector<int> adjList[])
{
    vector<int> color(V, -1);

    for(int i=0;i<V;i++)
    {
        if(color[i] == -1)
        {
            if(!is_comp_bipartite(i, V, adjList, color))
                return false;
        }
    }

    return true;
}

