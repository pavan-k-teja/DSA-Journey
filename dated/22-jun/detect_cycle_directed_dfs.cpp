#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

class Graph //directed
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
	bool isCyclic();
    bool checkForCycle(int node, bool visited[], bool curr[]);
};

void Graph::addEdge(int v, int w)
{
    adjList[v].push_back(w);
}

bool Graph::isCyclic()
{
    if(vertices == 0)
        return false;

    bool visited[vertices];
    bool curr[vertices];
    memset(visited, 0, sizeof(visited));
    memset(curr, 0, sizeof(curr));

    for(int i=0;i<vertices;i++)
    {
        if(!visited[i])
            if(checkForCycle(i, visited, curr))
                return true;
    }
    return false;
}

bool Graph::checkForCycle(int node, bool visited[], bool curr[])
{
    visited[node] = true;
    curr[node] = true;
    for(int i : adjList[node])
    {
        if(!visited[i])
        {
            if(checkForCycle(i, visited, curr))
                return true;
        }
        else if(curr[i])
            return true;
    }
    curr[node] = false;
    return false;
}

int main()
{

	Graph g(10);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.addEdge(3, 6);
	g.addEdge(6, 5);
	g.addEdge(7, 2);
	g.addEdge(7, 8);
	g.addEdge(8, 9);
	// g.addEdge(9, 7);

	cout<< g.isCyclic();

	return 0;
}
