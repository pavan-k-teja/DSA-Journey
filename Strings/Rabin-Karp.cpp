#include <bits/stdc++.h>
using namespace std;

/*
    Preprocessing Time Complexity - O(m)
    Searching Time Complexity - O(n+m)
    Space Complexity - O(n+m)
*/

vector<int> rabin_karp(string &s, string &t)
{
    // hash = sigma(s[i]*p) % m
    // pattern-s, text-t
    int p = 31; // prime nearly equal to input alphabet
    int m = 1e9 + 9; // large prime number to reduce collisions (1/m)
    int S = s.size();
    int T = t.size();


    vector<long long> p_pow(max(S, T)); // Precomputing the powers of p
    p_pow[0] = 1;
    for (int i = 1; i < p_pow.size(); i++)
        p_pow[i] = (p_pow[i - 1] * p) % m;

    long long hash_s = 0;
    for (int i = 0; i < S; i++)
        hash_s = (hash_s + (s[i] - 'a' + 1) * p_pow[i]) % m;

    vector<long long> hash(T + 1, 0);
    for (int i = 0; i < T; i++)
        hash[i + 1] = (hash[i] + (t[i] - 'a' + 1) * p_pow[i]) % m;
        

    vector<int> occurences;
    for (int i = 0; i <= T-S; i++)
    {
        long long cur_hash = (hash[i + S] + m - hash[i]) % m;
        if (cur_hash == hash_s * p_pow[i] % m)
            occurences.push_back(i);
    }
    return occurences;
}

int main()
{

    return 0;
}