#include <bits/stdc++.h>
using namespace std;

/*
    Preprocessing Time Complexity - O(m)
    Searching Time Complexity - O(n+m)
    Space Complexity - O(m)
*/


vector<int> prefix_function(string s)
{
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];

        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];

        if (s[i] == s[j])
            j++;
        
        pi[i] = j;
    }

    return pi;
}

vector<int> KMP(string haystack, string needle)
{
    vector<int> occurances;
    int N = haystack.size();
    int M = needle.size();

    vector<int> LPS = prefix_function(needle);

    int i = 0;
    int j = 0;
    while (i <= N - M)
    {
        while (j < M && haystack[i + j] == needle[j])
            j ++;
        
        // If mismatch occurs at first character
        if (j == 0)
            i ++;
        
        // If mismatch occurs at any other character
        else
        {
            if(j == M) // no mismatch
                occurances.push_back(i);
                
            j = LPS[j - 1];
            i = i + j - LPS[j - 1];
        }
    }

    return occurances;
}

int main()
{
    // string text ("There are two needles in this haystack with needles.");
    // string pattern ("needle");
    string text ("aaaaab");
    string pattern ("aaa");

    vector<int> occurances = KMP(text, pattern);

    for(int &idx : occurances)
        cout<<idx<<" ";

    return 0;
}