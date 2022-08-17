#include <bits/stdc++.h>
using namespace std;

bool is_comp_cyclic(int node, int V, vector<int> adjList[], vector<bool> &vis)
{
    queue<pair<int, int>> q;
    
    q.push({node, -1});
    vis[node] = true;

    while(!q.empty())
    {
        int n = q.front().first;
        int par = q.front().second;
        q.pop();
        
        for(int neighbour : adjList[n])
        {
            if(!vis[neighbour])
            {
                q.push({neighbour, n});
                vis[neighbour] = true;
            }
            else if(par!=neighbour)
                return true;
        }
    }
    return false;
}

bool isCyclic(int V, vector<int> adjList[])
{
    vector<bool> vis(V, false);

    for(int i=0;i<V;i++)
    {
        if(!vis[i] && is_comp_cyclic(i, V, adjList, vis))
            return true;
    }

    return false;
}

