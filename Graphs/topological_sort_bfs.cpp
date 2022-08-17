#include<bits/stdc++.h>
using namespace std;

void setIndegree(int V, vector<int> adj[], vector<int> &indegree)
{
    for(int i=0;i<V;i++)
    {
        for(int node : adj[i])
            indegree[node]++;
    }
}

vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> indegree(V, 0);
    vector<int> ans;

    setIndegree(V, adj, indegree);
    queue<int> q;
    for(int i=0;i<V;i++)
    {
        if(indegree[i] == 0)
            q.push(i);
    }

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for(int neigh : adj[node])
        {
            indegree[neigh]--;
            if(indegree[neigh] == 0)
                q.push(neigh);
        }
    }

    return ans;
}