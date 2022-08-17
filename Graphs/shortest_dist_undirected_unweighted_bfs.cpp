#include<bits/stdc++.h>
using namespace std;

vector<int> shortest_dist(int V, vector<int> adj[], int source)
{
    vector<int> dist(V, INT_MAX);
    dist[source] = 0;
    queue<int> q;
    q.push(source);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(int neigh : adj[node])
        {
            if(1 + dist[node] < dist[neigh])
            {
                dist[neigh] = 1 + dist[node];
                q.push(neigh);
            }
            
        }

    }

    return dist;
}