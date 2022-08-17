#include <bits/stdc++.h>
using namespace std;

bool is_comp_bipartite(int node, int V, vector<int> adjList[], vector<int> &color)
{
    for(int neigh : adjList[node])
    {
        if(color[neigh] == -1)
        {
            color[neigh] = 1 - color[node];
            if(!is_comp_bipartite(neigh, V, adjList, color))
                return false;
        }
        else if(color[node] == color[neigh])
            return false;
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
            color[i] = 0;
            if(!is_comp_bipartite(i, V, adjList, color))
                return false;
        }
    }

    return true;
}

