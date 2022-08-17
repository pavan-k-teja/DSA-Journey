#include <bits/stdc++.h>
using namespace std;

bool is_comp_cyclic(int node, int parent, vector<int> adjList[], vector<bool> &vis)
{
    vis[node] = true;
    
    for(int neighbour : adjList[node])
    {
        if(!vis[neighbour])
            if (is_comp_cyclic(neighbour, node, adjList, vis))
                return true;
        else if(parent != neighbour)
            return true;
    }

    return false;
}

bool isCyclic(int V, vector<int> adjList[])
{
    vector<bool> vis(V, false);

    for(int i=0;i<V;i++)
    {
        if(!vis[i] && is_comp_cyclic(i, -1, adjList, vis))
            return true;
    }

    return false;
}

