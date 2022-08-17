#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity

with adjMat and no heap -> O(V^2)
  -> O((V + E log V)
*/

int PrimsMST(int N, vector<pair<int, int>> adj[])
{
    int mst_wt = 0;

    vector<int> parent(N, -1); // need the parent node for output
    vector<int> weights(N, INT_MAX); // whts the min cost to this node from mstSet
    vector<bool> inMST(N, false); // check if a node is considered in the mst

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int src = 0;
    weights[src] = 0;
    parent[src] = -1;
    pq.push({0, src}); // dist, node
    
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if(inMST[u])
            continue;

        inMST[u] = true;

        for (auto it : adj[u])
        {
            int v = it.first;
            int weight = it.second;

            if (!inMST[v] && weight < weights[v])
            {
                parent[v] = u;
                weights[v] = weight;
                pq.push({weights[v], v});
            }
        }
    }

    for (int i = 1; i < N; i++)
        cout << parent[i] << " - " << i << " \n";


    return mst_wt;
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> adj[N];

    int a, b, wt;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> wt;
        adj[a].push_back(make_pair(b, wt));
        adj[b].push_back(make_pair(a, wt));
    }
    PrimsMST(N, adj);

    return 0;
}
/*
    Test Case:
    6 7
    0 1 5
    0 2 10
    0 3 100
    1 3 50
    1 4 200
    3 4 250
    4 5 50
*/

    