#include<bits/stdc++.h>
using namespace std;

void solve(vector <string> &A, vector <string> &ans, int index, string &s){
    if (s.length()==A.size()){
        ans.push_back(s);
        return;
    }
   
    for(int j=0;j<A[index].size();j++){
        s.push_back(A[index][j]);
        solve(A, ans, index+1, s);
        s.pop_back();
        
    }
}
vector<string> specialStrings(vector<string> &A) {
    vector <string> ans;
    string s;
    solve(A, ans, 0, s);
    return ans;
}


int main()
{

    

    return 0;
}