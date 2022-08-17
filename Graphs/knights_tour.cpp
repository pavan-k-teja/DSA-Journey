#include<bits/stdc++.h>
using namespace std;

int dfs(vector<vector<bool>> &vis, int sx, int sy, int dx, int dy)
{
    if(sx<0 || sx >=vis.size() || sy<0 || sy>=vis[0].size() || vis[sx][sy])
        return INT_MAX;
    
    if(sx == dx && sy == dy)
        return 0;

    int mn = INT_MAX;
    vis[sx][sy] = true;
    mn = min(mn, dfs(vis, sx-2, sy+1, dx, dy));
    mn = min(mn, dfs(vis, sx-1, sy+2, dx, dy));
    mn = min(mn, dfs(vis, sx+1, sy+2, dx, dy));
    mn = min(mn, dfs(vis, sx+2, sy+1, dx, dy));
    mn = min(mn, dfs(vis, sx+2, sy-1, dx, dy));
    mn = min(mn, dfs(vis, sx+1, sy-2, dx, dy));
    mn = min(mn, dfs(vis, sx-1, sy-2, dx, dy));
    mn = min(mn, dfs(vis, sx-2, sy-1, dx, dy));
    vis[sx][sy] = false;

    cout<<mn<<"\n";

    if(mn == INT_MAX)
        return INT_MAX;
    
    return mn + 1 ;

}

int knight(int A, int B, int C, int D, int E, int F) {

    if(C == E && D == F)
        return 0;
    
    vector<vector<bool>> vis(A, vector<bool> (B, false));

    int count = dfs(vis, C-1, D-1, E-1, F-1);
    if(count == INT_MAX)
        return -1;
    return count;

}

int main()
{
    int A, B, C, D, E, F;
    cin >> A>> B>> C>> D>> E>> F;

    cout<< knight(A, B, C, D, E, F);

    return 0;
}