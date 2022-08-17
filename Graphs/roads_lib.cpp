void dfs(int node, vector<int> adjList[], bool vis[])
{
    vis[node] = true;
    for(auto& neighbour : adjList[node])
    {
        if(!vis[neighbour])
            dfs(neighbour, adjList, vis);
    }
    cout<<"here";
}

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {

    if(c_lib <= c_road)
        return (long) n * (long) c_lib;
    
    vector<int> adjList[n+1];
    
    for(auto& pair : cities)
    {
        adjList[pair[0]].push_back(pair[1]);
        adjList[pair[1]].push_back(pair[0]);
    }

    int comp=0;
    bool vis[n+1];
    memset(vis, 0, sizeof vis);
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs(i, adjList, vis);
            comp++;
        }
        
    }
    return (((long) n - (long) comp) * (long) c_road) + ((long)comp * (long) c_lib);
}