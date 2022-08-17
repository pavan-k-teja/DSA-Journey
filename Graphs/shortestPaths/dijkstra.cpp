#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity

without heap -> O(V^2)
binary heap  -> O((V+E) log V)
*/

class Solution
{
public:
    vector<int> DijkstraDist(int V, vector<pair<int, int>> adj[], int src)
    { // adj list has array of vector of pairs. each pair has {node, weight}
        vector<int> distArr(V, INT_MAX);
        distArr[src] = 0;
        vector<bool> vis(V, 0);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // default priority queue is max heap but we want minheap
        pq.push({0, src}); // first element is dist, second is node

        while (!pq.empty())
        {
            pair<int, int> ele = pq.top();
            pq.pop();

            int distTravelled = ele.first;
            int node = ele.second;

            if (vis[node]) // we already found best dist to node and also traversed its neighbours
                continue;
                
            vis[node] = true;

            for (pair<int, int> neighbour : adj[node])
            {
                if (distTravelled + neighbour.second < distArr[neighbour.first])
                {
                    distArr[neighbour.first] = distTravelled + neighbour.second;
                    pq.push({distArr[neighbour.first], neighbour.first});
                }
            }
        }

        return distArr;
    }
};

/*

Test Case
1
5 9
0 1 10
0 2 3
1 2 1
1 3 2
2 1 4
2 3 8
2 4 2
3 4 7
4 3 9
4
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
        vector<int> dist = obj.DijkstraDist(V, adj, src);
        for (int i = 0; i < dist.size(); i++)
        {
            cout << "Distance from node " << src << " to node " << i << " ---> " << (dist[i] == INT_MAX ? -1 : dist[i]) << "\n";
        }
        cout << endl;
    }
    return 0;
}