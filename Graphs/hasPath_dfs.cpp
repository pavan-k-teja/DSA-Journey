#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool dfs(vector<bool> &vis, vector<int> adj[], int src, int dest)
    {
        if(src == dest)
            return true;

        vis[src] = true;

        for(int neighbour : adj[src])
        {
            if(!vis[neighbour] && dfs(vis, adj, neighbour, dest))
                return true;
        }

        return false;
    }

public:
    bool hasPath(int V, vector<int> adj[], int src, int dest) // 1-indexed graph
    {
        vector<bool> vis(V + 1, false);

        return dfs(vis, adj, src, dest);
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
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

        Solution obj;
        int src, dest;
        cin >> src >> dest;
        cout<< obj.hasPath(V, adj, src, dest);
        
        cout << endl;
    }
    return 0;
}