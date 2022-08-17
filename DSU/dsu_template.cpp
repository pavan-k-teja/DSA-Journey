#include <bits/stdc++.h>
using namespace std;

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

// Without path compression and no rank -> O(n)
// Only one optimization(any) -> O(log n)

// Using both ...
// Single call -> O(log n)
// Multiple calls back to back -> O(alpha(n)) -> Inverse Ackermann function -> nearly constant
    

int main()
{
    DSU d(5);
    return 0;
}