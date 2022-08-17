#include <iostream>
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
	bool isCycle();
    bool checkForCycle(int node, int parent, bool visited[]);
};

void Graph::addEdge(int v, int w)
{
    adjList[v].push_back(w);
    adjList[w].push_back(v);
}

bool Graph::isCycle()
{
    if(vertices == 0)
        return false;

    bool visited[vertices];
    for(int i=0;i<vertices;i++)
        visited[i] = false;

    for(int i=0;i<vertices;i++)
    {
        if(!visited[i])
            if(checkForCycle(i, -1, visited) == true)
                return true;
    }
    return false;
}

bool Graph::checkForCycle(int node, int parent, bool visited[])
{
    visited[node] = true;
    for(int i : adjList[node])
    {
        if(!visited[i])
        {
            if(checkForCycle(i, node, visited))
                return true;
        }
        else if(parent != i)
            return true;
    }
    return false;
}

int main()
{

	Graph g(7);
	g.addEdge(0, 1);
	g.addEdge(1, 3);
	g.addEdge(1, 6);
	g.addEdge(3, 5);
	// g.addEdge(5, 6);
	g.addEdge(2, 4);

	cout<< g.isCycle();

	return 0;
}
