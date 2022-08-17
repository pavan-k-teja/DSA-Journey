#include <bits/stdc++.h>
using namespace std;

#define IS_CUTPOINT(v) ;

int n;                   // number of nodes
vector<vector<int>> adj; // adjacency list of graph

vector<bool> visited;
vector<int> tin; // entry time
vector<int> low; // lowest time to reach a point from start of dfs
int timer;

void dfs(int v, int parent)
{
    visited[v] = true;
    tin[v] = low[v] = timer++;

    int children = 0;

    for (int neigh : adj[v])
    {
        if (neigh == parent)
            continue;
        if (visited[neigh])
        {
            low[v] = min(low[v], tin[neigh]);
        }
        else
        {
            dfs(neigh, v);
            low[v] = min(low[v], low[neigh]);
            if (low[neigh] >= tin[v] && parent != -1)
                IS_CUTPOINT(v);
            children++;
        }
    }
    if (parent == -1 && children > 1)
        IS_CUTPOINT(v);
}

void find_cutpoints()
{
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
            dfs(i, -1);
    }
}

int main()
{

    return 0;
}