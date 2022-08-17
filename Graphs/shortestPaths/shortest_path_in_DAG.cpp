
#include <bits/stdc++.h>
using namespace std;

// DAG can be represented as a linear graph with no back edges
// https://media.geeksforgeeks.org/wp-content/uploads/shortestpathsteps.png

/*
Time Complexity -> O ( V + E )

*/

void findTopoSort(int node, int vis[], stack<int> &st, vector<pair<int, int>> adj[])
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it.first])
        {
            findTopoSort(it.first, vis, st, adj);
        }
    }
    st.push(node);
}

void shortestPath(int src, int V, vector<pair<int, int>> adj[])
{
    int vis[V] = {0};

    stack<int> st;
    for (int i = 0; i < V; i++) // O(V+E)
        if (!vis[i])
            findTopoSort(i, vis, st, adj);

    int dist[V];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    while (!st.empty()) // O(V+E)
    {
        int node = st.top();
        st.pop();

        if (dist[node] != INT_MAX)
        {
            for (auto neighbour : adj[node])
            {
                if (dist[node] + neighbour.second < dist[neighbour.first])
                {
                    dist[neighbour.first] = dist[node] + neighbour.second;
                }
            }
        }
    }

    for (int i = 0; i < V; i++)
        (dist[i] == INT_MAX) ? cout << "INT_MAX " : cout << dist[i] << " ";
}

/*
test case
6 9
0 1 5
0 2 3
1 3 6
1 2 2
2 4 4
2 5 2
2 3 7
3 4 -1
4 5 -2
*/
int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }

    shortestPath(0, n, adj);

    return 0;
}