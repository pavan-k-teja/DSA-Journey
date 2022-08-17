#include <bits/stdc++.h>
using namespace std;

void findTopoComp(int node, vector<int> adjList[], vector<bool> &vis, vector<int> &ans)
{
    vis[node] = true;

    for (int i : adjList[node])
    {
        if (!vis[i])
        {
            findTopoComp(i, adjList, vis, ans);
        }
    }

    ans.push_back(node);
}

vector<int> topoSort(int V, vector<int> adjList[])
{
    vector<bool> vis(V, false);
    vector<int> ans;

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            findTopoComp(i, adjList, vis, ans);
    }
    reverse(ans.begin(), ans.end());

    return ans;
}