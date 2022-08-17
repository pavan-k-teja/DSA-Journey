#include <bits/stdc++.h>
using namespace std;

/*
    Time Complexity -> O(V + E log V)
*/

class DSU // Disjoint Set Union
{
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n) : parent(n), rank(n, 0)
    {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find_set(int v) // path compression
    {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) // union by rank
    {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
        {
            if (rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }
};

class Solution
{
public:
    int kruskalMST(int V, vector<vector<int>> edgeList)
    { // graph as edgeList

        int mst_wt = 0;
        
        sort(edgeList.begin(), edgeList.end());
        DSU dsu(V);

        for(auto& edge : edgeList)
        {
            int weight = edge[0];
            int fromNode = edge[1];
            int toNode = edge[2];

            int set_from = dsu.find_set(fromNode);
            int set_to = dsu.find_set(toNode);

            if (set_from != set_to) // no cycle
            {
                cout << fromNode << " - " << toNode << endl;

                mst_wt += weight;
                dsu.union_sets(set_from, set_to);
            }

            // Notice: since the MST will contain exactly V-1 edges, we can stop the for loop once we found that many.
        }
  
        return mst_wt;
    }
};

/*

Test Case
1
9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7
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

        vector<vector<int>> graph;

        for (int i = 0; i < E; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            graph.push_back({w, u, v}); // weight at 0-index cuz ez to sort
        }

        Solution obj;
        
        cout << "\nEdges of MST are \n";
        int mst_wt = obj.kruskalMST(V, graph);
    
        cout << "\nWeight of MST is " << mst_wt;
    
        return 0;
    }
    return 0;
}