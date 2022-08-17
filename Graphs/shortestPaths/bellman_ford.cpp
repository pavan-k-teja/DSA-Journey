#include <bits/stdc++.h>
using namespace std;

/*
    Time Complexity -> O(VE)
*/

class Solution
{
public:
    vector<int> BellmanFord(int V, vector<pair<int, int>> adj[], int src)
    {   // adj list has array of vector of pairs. each pair has {node, weight}
        // we need edge list for bellman ford
        vector<vector<int>> edges;  // {from, to, weight}
        for (int i = 0; i < V; i++) // Creating edge list. Not part of algo
        {
            for (auto &node : adj[i])
                edges.push_back({i, node.first, node.second});
        }

        // Algorithm starts here
        vector<int> distArr(V, INT_MAX);
        distArr[src] = 0;

        for (int i = 1; i <= V - 1; i++) // relax V-1 times
        {
            bool isUpdated = false;

            for (auto edge : edges)
            {
                if (distArr[edge[0]] != INT_MAX && distArr[edge[0]] + edge[2] < distArr[edge[1]])
                {
                    distArr[edge[1]] = distArr[edge[0]] + edge[2];
                    isUpdated = true;
                }
            }

            if(isUpdated == false) // a small optimization
                return distArr;
        }

        for (auto edge : edges) // check if any negative cycle
        {
            if (distArr[edge[0]] != INT_MAX && distArr[edge[0]] + edge[2] < distArr[edge[1]])
                return {};
        }

        return distArr;
    }
};

/*

Test Case
1
6 7
0 1 5
1 2 -2
1 5 -3
2 4 3
3 2 6
3 4 -2
5 3 1
0
*/

int main()
{
    int tc;
    cin >> tc;
    // for multiple graphs
    while (tc--)
    {
        int V, E;
        cin >> V >> E;

        vector<pair<int, int>> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            // adj[v].push_back({u, w});
        }

        Solution obj;
        int src;
        cin >> src;
        vector<int> dist = obj.BellmanFord(V, adj, src);
        if (dist.empty())
            cout << "Contains negative cycle\n";
        for (int i = 0; i < dist.size(); i++)
        {
            cout << "Distance from node " << src << " to node " << i << " ---> " << (dist[i] == INT_MAX ? -1 : dist[i]) << "\n";
        }
        cout << endl;
    }
    return 0;
}