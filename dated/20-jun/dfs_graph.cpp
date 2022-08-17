#include<iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph //undirected
{
	int vertices;
	vector<vector<int>> adjList;
public:
	Graph(int V)
    {
        vertices = V;
        // for(int i=0;i<V;i++)
        // {
        //     vector<int> lst;
        //     adjList.push_back(lst);
        // }
        adjList.resize(V);
    }

	void addEdge(int v, int w);
	vector<int> DFS_iter();
    vector<int> DFS_rec();
    vector<int> dfs_helper_iter(int start, bool visited[]);
    void dfs_helper_rec(int node, bool visited[], vector<int> &dfs);
};

void Graph::addEdge(int v, int w)
{
    adjList[v].push_back(w);
    adjList[w].push_back(v);
}

vector<int> Graph::DFS_iter()
{
    if(vertices == 0)
        return {};

	bool visited[vertices];
	for(int i = 0; i < vertices; i++)
		visited[i] = false;

    vector<int> dfs;
    for(int i=0; i<vertices; i++)
    {
        if(!visited[i])
        {
            vector<int> sub_dfs = dfs_helper_iter(i, visited);
            dfs.insert(dfs.end(), sub_dfs.begin(), sub_dfs.end());
        }
    }
    return dfs;
}

vector<int> Graph::dfs_helper_iter(int start, bool visited[])
{
    vector<int> sub_dfs;
    stack<int> s;

	s.push(start);
    visited[start] = true;
    sub_dfs.push_back(start);

	while(!s.empty())
	{
		int vertex = s.top();
		s.pop();

		for (int i : adjList[vertex])
        {
			if (!visited[i])
            {
                s.push(i);
                visited[i]= true;
                sub_dfs.push_back(i);
            }
        }
	}
    return sub_dfs;
}

vector<int> Graph::DFS_rec()
{
    if(vertices == 0)
        return {};

	bool visited[vertices];
	for(int i = 0; i < vertices; i++)
		visited[i] = false;

    vector<int> dfs;
    for(int i=0; i<vertices; i++)
    {
        if(!visited[i])
        {
            dfs_helper_rec(i, visited, dfs);
        }
    }
    return dfs;
}

void Graph::dfs_helper_rec(int node, bool visited[], vector<int> &dfs)
{
    visited[node] = true;
    dfs.push_back(node);

    for(int i: adjList[node])
        if(!visited[i])
            dfs_helper_rec(i, visited, dfs);
}


int main()
{

	Graph g(7);
	g.addEdge(0, 1);
	g.addEdge(1, 3);
	g.addEdge(1, 6);
	g.addEdge(3, 5);
	g.addEdge(5, 6);
	g.addEdge(2, 4);

	vector<int> dfs = g.DFS_rec();

    for(int i:dfs)
    {
        cout<< i <<" ";
    }

	return 0;
}
