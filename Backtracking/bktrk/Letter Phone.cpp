#include<bits/stdc++.h>
using namespace std;

unordered_map<int, vector<char>> mp;

void dfs(vector<string> &ans, string &A, int index, string &temp)
{
    int n = A.size();
    if(index==n)
    {
        ans.push_back(temp);
        return;
    }

        for(char currno:mp[A[index] - '0'])
        {
            temp.push_back(currno);
            dfs(ans, A, index + 1, temp);
            temp.pop_back();
        }
    


}

vector<string> letterCombinations(string A) {



    // mp[0] = "0";
    // mp[1] = "1";
    // mp[2] = "abc";
    // mp[3] = "def";
    // mp[4] = "ghi";
    // mp[5] = "jkl";
    // mp[6] = "mno";
    // mp[7] = "pqrs";
    // mp[8] = "tuv";
    // mp[9] = "wxyz";



    mp[0] = {'0'};
    mp[1] = {'1'};
    mp[2] = {'a','b','c'};
    mp[3] = {'d','e','f'};
    mp[4] = {'g','h','i'};
    mp[5] = {'j', 'k', 'l'};
    mp[6] = {'m', 'n', 'o'};
    mp[7] = {'p', 'q', 'r', 's'};
    mp[8] = {'t', 'u', 'v'};
    mp[9] = {'w', 'x', 'y', 'z'};





  
    string temp ="";
    vector<string> ans;
    dfs(ans, A, 0, temp);
    sort(ans.begin(), ans.end());
    return ans;
}



int main()
{

    

    return 0;
}