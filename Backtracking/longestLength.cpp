#include<bits/stdc++.h>
using namespace std;

void findLongestPath(vector<vector<int>> &vect, int sx, int sy, int dx, int dy, int lenTillNow, int &maxLen)
{
    if(sx==dx && sy==dy)
    {
        maxLen = max(lenTillNow, maxLen);
        return;
    }

    if(sx<0 || sx>=vect.size() || sy<0 || sy>=vect[0].size() || vect[sx][sy]!=1)
        return;

    // cout<<"here ";
    vect[sx][sy]=2;

    findLongestPath(vect, sx-1, sy, dx, dy, lenTillNow+1, maxLen);
    findLongestPath(vect, sx, sy+1, dx, dy, lenTillNow+1, maxLen);
    findLongestPath(vect, sx+1, sy, dx, dy, lenTillNow+1, maxLen);
    findLongestPath(vect, sx, sy-1, dx, dy, lenTillNow+1, maxLen);

    vect[sx][sy]=1;
}


int main()
{
    vector<vector<int>> vect =  {
                                    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                                    { 1, 1, 0, 1, 1, 0, 1, 1, 0, 1 },
                                    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
                                };
    
    int maxLen=0;
    findLongestPath(vect, 0, 0, 1, 7, 0, maxLen);
    cout<<maxLen;

    return 0;
}