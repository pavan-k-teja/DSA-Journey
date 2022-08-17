#include<bits/stdc++.h>
using namespace std;

/* This graph does NOT have a cycle

 O -----> O
 |        |
 |        |
 v        v
 O -----> O
 
*/

void setIndegree(int V, vector<int> adj[], vector<int> &indegree)
{
    for(int i=0;i<V;i++)
    {
        for(int node : adj[i])
            indegree[node]++;
    }
}

bool isCyclic(int V, vector<int> adj[])
{
    vector<int> indegree(V, 0);

    setIndegree(V, adj, indegree); 
    queue<int> q;
    for(int i=0;i<V;i++)
    {
        if(indegree[i] == 0)
            q.push(i);
    }

    int cnt = 0;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        cnt++;

        for(int neigh : adj[node])
        {
            indegree[neigh]--;
            if(indegree[neigh] == 0)    
                q.push(neigh);
        }
    }

    return ( cnt != V );
}