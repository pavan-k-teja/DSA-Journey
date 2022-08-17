#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool hasPath(int V, vector<int> adj[], int src, int dest) // 0-indexed graph
    {
        if (src == dest)
            return true;

        vector<int> vis(V, 0);

        queue<int> q;
        q.push(src);
        vis[src] = 1;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto neighbour : adj[node])
            {
                if (!vis[neighbour])
                {
                    if (neighbour == dest)
                        return true;
                    q.push(neighbour);
                    vis[neighbour] = 1;
                }
            }
        }

        return false;
    }
};

int main()
{
    int tc;
    cin >> tc;
    // for multiple graphs
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
            // 		adj[v].push_back(u); // uncomment this for undirected graoh
        }

        Solution obj;
        int src, dest;
        cin >> src >> dest;
        cout << obj.hasPath(V, adj, src, dest);

        cout << endl;
    }
    return 0;
}