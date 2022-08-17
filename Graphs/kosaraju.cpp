#include<bits/stdc++.h>
using namespace std;


void fillStack(int node, vector<int> adjList[], vector<bool> &visited, stack<int>&s)
{
    visited[node] = true;

    for(int neigh : adjList[node])
    {
        if(!visited[neigh])
            fillStack(neigh, adjList, visited, s);
    }
    s.push(node);
}

void dfs(int node, vector<int> adjList[], vector<bool> &visited)
{
    cout<< node << " ";
    visited[node] = true;

    for(int neigh : adjList[node])
    {
        if(!visited[neigh])
            dfs(neigh, adjList, visited);
    }
}


void Kosaraju(int V, vector<int> adjList[])
{
    // fill the stack to find start side
    stack<int> s;
    vector<bool> visited(V, false);
    fillStack(0, adjList, visited, s);

    // reverse the edges on a new space
    vector<int> reversedGraph[V];
    for(int i=0;i<V;i++)
    {
        for(int neigh : adjList[i])
            reversedGraph[neigh].push_back(i);
    }

    // reset the visited arr
    fill(visited.begin(), visited.end(), false);

    // each component is a SCC
    while(!s.empty())
    {
        int node = s.top();
        s.pop();

        if(!visited[node])
        {
            cout<< "SCC : ";
            dfs(node, reversedGraph, visited);
            cout<<"\n";
        }

    }
    

}

int main()
{

    int n=6, m=7;
	vector<int> adj[n]; 
	adj[0].push_back(3);
	adj[2].push_back(0);
	adj[3].push_back(2);
	adj[3].push_back(5);
	adj[4].push_back(1);
	adj[5].push_back(4);
	adj[1].push_back(5);

    Kosaraju(n, adj);
    

    return 0;
}