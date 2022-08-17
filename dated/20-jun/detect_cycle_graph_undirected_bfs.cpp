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
    bool checkForCycle(int node, bool visited[]);
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
            if(checkForCycle(i, visited) == true)
                return true;
    }
    return false;
}

bool Graph::checkForCycle(int node, bool visited[])
{
    queue<pair<int, int>> q;
    q.push({node, -1});
    visited[node] = true;

    while(!q.empty())
    {
        pair<int, int> pair_q = q.front();
        q.pop();

        int parent_node = pair_q.second;
        int curr_node = pair_q.first;
        for(int i : adjList[curr_node])
        {
           
            if(visited[i] == true)
            {
                if(parent_node != i)
                    return true;
            }
            else
            {
                q.push({i, curr_node});
                visited[i] = true;
            }
        }
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
