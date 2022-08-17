#include <bits/stdc++.h>
using namespace std;


void dfs(int v, int par, vector<int> adj[], vector<bool> &visited, int &timer, vector<int> &tin, vector<int> &low, vector<pair<int, int>> result)
{
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v])
    {
        if (to == par)
            continue;
        if (visited[to])
        {
            low[v] = min(low[v], tin[to]);
        }
        else
        {
            dfs(to, v, adj, visited, timer, tin, low, result);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                result.push_back({v, to});
        }
    }
}

vector<pair<int, int>> find_bridges(int V, vector<int> adj[])
{
    vector<pair<int, int>> result;
    int timer = 0;
    vector<bool> visited(V, false);
    vector<int> tin(V, -1);
    vector<int> low(V, -1);
    for (int i = 0; i < V; ++i)
    {
        if (!visited[i])
            dfs(i, -1, adj, visited, timer, tin, low, result);
    }

    return result;
}


int main()
{
    
    int V, E;
    cin >> V >> E;

    vector<int> adj[V];

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<pair<int, int>> result = find_bridges(V, adj);
    for (auto& edge : result)
    {
        cout << edge.first <<" - "<< edge.second << "\n";
    }
    cout << endl;
    
    return 0;
}