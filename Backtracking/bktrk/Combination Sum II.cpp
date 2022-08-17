#include<bits/stdc++.h>
using namespace std;


void gen_comb2(set<vector<int> > &ans, vector<int> curr, int start, int sum, vector<int> inp, int target){
	if(start == inp.size()){
		if(sum == target)
			ans.insert(curr);
		return;
	}
	gen_comb2(ans, curr, start+1, sum, inp, target);
	curr.push_back(inp[start]);
	gen_comb2(ans, curr, start+1, sum+inp[start], inp, target);
}

vector<vector<int> > Solution::combinationSum(vector<int> &inp, int target) {
	set<vector<int> > ans;
	vector<int> curr;
	sort(inp.begin(), inp.end());
	gen_comb2(ans, curr, 0, 0, inp, target);
	vector<vector<int> > sol(ans.begin(), ans.end());
	return sol;
}

int main()
{

    

    return 0;
}