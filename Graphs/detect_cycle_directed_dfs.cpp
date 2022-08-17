#include <bits/stdc++.h>
using namespace std;

/* This graph does NOT have a cycle

 O -----> O
 |        |
 |        |
 v        v
 O -----> O
 
*/

bool is_comp_cyclic(int node, vector<int> adjList[], vector<bool> &vis, vector<bool> &dfs_vis)
{
    vis[node] = true;
    dfs_vis[node] = true;

    for(int i : adjList[node])
    {
        if(!vis[i])
        {
            if(is_comp_cyclic(i, adjList, vis, dfs_vis))
                return true;
        }
        else if(dfs_vis[i])
            return true;
    }
    dfs_vis[node] = false;
    return false;

}

bool isCyclic(int V, vector<int> adjList[])
{
    vector<bool> vis(V, false);
    vector<bool> dfs_vis(V, false);

    for(int i=0;i<V;i++)
    {
        if(!vis[i] && is_comp_cyclic(i, adjList, vis, dfs_vis))
            return true;
    }

    return false;
}

