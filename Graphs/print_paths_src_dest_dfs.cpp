#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void printPath(vector<int> path)
    {
        for (auto i : path)
            cout << i << " ";
        cout << "\n";
    }

    void dfs(vector<bool> &vis, vector<int> adj[], int src, int dest, vector<int> &path)
    {
        path.push_back(src);

        if (src == dest)
        {
            printPath(path);
            path.pop_back();
            return;
        }
        vis[src] = true;

        for (int nei : adj[src])
        {
            if (!vis[nei])
            {
                dfs(vis, adj, nei, dest, path);
            }
        }
        path.pop_back();
        vis[src] = false;
    }

public:

    void printPaths(int V, vector<int> adj[], int src, int dest)
    {
        vector<bool> vis(V, false);
        vector<int> path;

        dfs(vis, adj, src, dest, path);
    }
};

/*
Test case
1
7 8
0 1
1 2
2 3
0 3
3 4
4 5
5 6
4 6
0 6
----
1
7 9
0 1
0 3
1 2
2 3
2 5
3 4
4 5
4 6
5 6
0 6
*/

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

        int src, dest;
        cin >> src >> dest;
        Solution obj;
        obj.printPaths(V, adj, src, dest);
    }
    return 0;
}