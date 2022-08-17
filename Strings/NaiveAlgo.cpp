#include <bits/stdc++.h>
using namespace std;

/*
    Preprocessing Time Complexity - O(1)
    Searching Time Complexity - O(m*(n-m+1))
    Space Complexity - O(1)
*/

vector<int> search(string pat, string txt)
{
    int M = pat.size();
    int N = txt.size();
    vector<int> ans;

    for (int i = 0; i <= N - M; i++)
    {
        int j = 0;

        while (j < M && txt[i + j] == pat[j])
            j++;

        if (j == M)
            ans.push_back(i);
    }

    return ans;
}

int main()
{
    string txt = "AABAACAADAABAABAA";
    string pat = "AABA";

    vector<int> ans = search(pat, txt);
    for (auto &idx : ans)
        cout << idx << " " << txt[idx] << "\n";

    return 0;
}