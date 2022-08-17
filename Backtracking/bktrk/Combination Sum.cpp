#include<bits/stdc++.h>
using namespace std;

void f(vector<int> &A, int st, int B, vector<int> currSet, vector<vector<int>> &res){
    if(B == 0){
        res.push_back(currSet);
        return;
    }
    int n = A.size();
    if(st == n || B<0){
        return;
    }

    f(A, st+1, B, currSet, res);
    currSet.push_back(A[st]);
    f(A, st, B-A[st], currSet, res);
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    vector<vector<int>> res;
    vector<int> currSet, a;

    sort(A.begin(), A.end());
    a.push_back(A[0]);
    for(int i = 1; i<A.size(); i++){
        if(A[i]==A[i-1]) continue;
        a.push_back(A[i]);
    }
    f(a, 0, B, currSet, res);
    reverse(res.begin(), res.end());
    return res;
}

    

int main()
{

    

    return 0;
}