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
	bool isBipartite();
    bool checkBipartite(int node, int parent, int color[]);
};

void Graph::addEdge(int v, int w)
{
    adjList[v].push_back(w);
    adjList[w].push_back(v);
}


bool Graph::isBipartite()
{
    if(vertices == 0)
        return false;

    int color[vertices];
    for(int i=0;i<vertices;i++)
        color[i] = -1;

    for(int i=0;i<vertices;i++)
    {
        if(color[i] == -1)
            if(checkBipartite(i, -1, color) == false)
                return false;
    }
    return true;
}

bool Graph::checkBipartite(int node, int parent, int color[])
{
    color[node] = !color[parent];

    for(int child : adjList[node])
    {
        if(color[child] == -1)
        {
            if(checkBipartite(child, node, color) == false)
                return false;
        }
        else if(color[child] == color[node])
            return false;
    }
    
    return true;
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
	// g.addEdge(0, 6);

	cout<< g.isBipartite();

	return 0;
}
