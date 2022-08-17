#include<bits/stdc++.h>
using namespace std;
void helper(int index,vector<int> &A,vector<int> tempAns,vector<vector<int> > &ans)
{
    for(int i=index;i<A.size();i++)
    {
        tempAns.push_back(A[i]);
        ans.push_back(tempAns);
        helper(i+1,A,tempAns,ans);
        while(i<A.size()-1 && A[i] == A[i+1])
            i++;
        tempAns.pop_back();
    }
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    vector<vector<int> > ans;
    vector<int> tempAns;
    ans.push_back(tempAns);
    if(A.size() == 0)
        return ans;
    sort(A.begin(),A.end());
    helper(0,A,tempAns,ans);
    return ans;
}




int main()
{

    

    return 0;
}