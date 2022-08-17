#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &dfs_ans)
    {
        vis[node] = 1;
        dfs_ans.push_back(node);
        for (int neighbour : adj[node])
        {
            if (!vis[neighbour])
                dfs(neighbour, vis, adj, dfs_ans);
        }
    }

public:
    vector<int> dfsOfGraph(int V, vector<int> adj[]) // 1-indexed graph
    {
        vector<int> dfs_ans;
        vector<int> vis(V + 1, 0);
        for (int i = 1; i <= V; i++)
        {
            if (!vis[i])
                dfs(i, vis, adj, dfs_ans);
        }
        return dfs_ans;
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
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}