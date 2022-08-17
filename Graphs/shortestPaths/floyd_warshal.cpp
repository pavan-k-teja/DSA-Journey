#include <bits/stdc++.h>
using namespace std;

/*
    Time Complexity -> O(V^3)
*/

class Solution
{
public:
    vector<vector<int>> FloydWarshall(int V, vector<pair<int, int>> adj[], int src)
    {   // adj list has array of vector of pairs. each pair has {node, weight}
        // adj mat is preferred
        vector<vector<int>> dist(V, vector<int>(V, INT_MAX));
        for (int i = 0; i < V; i++)
        {
            for (auto &node : adj[i])
                dist[i][node.first] = node.second;
            dist[i][i] = 0;
        }

        for (int intermediary = 0; intermediary < V; intermediary++)
        {
            for (int from = 0; from < V; from++)
            {
                for (int to = 0; to < V; to++)
                {
                    if ((dist[intermediary][to] != INT_MAX && dist[from][intermediary] != INT_MAX) && dist[from][to] > (dist[from][intermediary] + dist[intermediary][to]))
                        dist[from][to] = dist[from][intermediary] + dist[intermediary][to];
                }
            }
        }
        
        // If distance of any vertex from itself becomes negative, then there is a negative weight cycle.
        for (int i = 0; i < V; i++)
        {
            if (dist[i][i] < 0)
                return {};
        }

        return dist;
    }
};

/*

Test Case
1
6 7
0 1 5
1 2 2
1 5 3
2 4 3
3 2 6
3 4 2
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
        vector<vector<int>> dist = obj.FloydWarshall(V, adj, src);

        if(dist.empty())
        {
            cout<<"Has negative edge cycle";
            return 0;
        }
        for (int i = 0; i < dist.size(); i++)
        {
            for (int j = 0; j < dist[0].size(); j++)
            {
                cout << ((dist[i][j] != INT_MAX) ? dist[i][j] : -1) << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}