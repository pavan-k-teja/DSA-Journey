#include <bits/stdc++.h>
using namespace std;

void get(string A, int index, vector<string> &temp, vector<vector<string>> &res)
{
    if (index == A.size())
    {
        res.push_back(temp);
        return;
    }
    for (int i = index; i < A.size(); i++)
    {
        string st = A.substr(index, i - index + 1);
        string st2 = st;
        reverse(st2.begin(), st2.end());
        if (st == st2)
        {
            temp.push_back(st);
            get(A, i + 1, temp, res);
            temp.pop_back();
        }
    }
}

vector<vector<string>> partition(string A)
{
    vector<vector<string>> res;
    vector<string> temp;
    get(A, 0, temp, res);
    return res;
}

int main()
{

    return 0;
}