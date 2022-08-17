#include<iostream>
#include <vector>
#include <queue>

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
    //TC = 0[N+E] and SC = 0[N+E] + O[N] + O[N]
	vector<int> BFS();
    vector<int> bfs_helper(int start, bool visited[]);
};

void Graph::addEdge(int v, int w)
{
    adjList[v].push_back(w);
    adjList[w].push_back(v);
}

vector<int> Graph::bfs_helper(int start, bool visited[])
{
    vector<int> sub_bfs;
    queue<int> q;

	q.push(start);
    visited[start] = true;
    sub_bfs.push_back(start);

	while(!q.empty())
	{
		int vertex = q.front();
		q.pop();

		for (int i : adjList[vertex])
        {
			if (!visited[i])
            {
                q.push(i);
                visited[i]= true;
                sub_bfs.push_back(i);
            }
        }
	}
    return sub_bfs;
}

vector<int> Graph::BFS()
{
    if(vertices == 0)
        return {};

	bool visited[vertices];
	for(int i = 0; i < vertices; i++)
		visited[i] = false;

    vector<int> bfs;
    for(int i=0; i<vertices; i++)
    {
        if(!visited[i])
        {
            vector<int> sub_bfs = bfs_helper(i, visited);
            bfs.insert(bfs.end(), sub_bfs.begin(), sub_bfs.end());
        }
    }
    return bfs;
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

	vector<int> bfs = g.BFS();

    for(int i:bfs)
    {
        cout<< i <<" ";
    }

	return 0;
}
