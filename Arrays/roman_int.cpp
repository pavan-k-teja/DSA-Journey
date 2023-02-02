#include <bits/stdc++.h>
using namespace std;

int romanToInt(string s)
{
    unordered_map<char, int> mp = {{'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};
    int res = 0;

    for (int i = 0; i < s.size(); i++) // works cuz s[s.size]=='\0'. Hence fails the if statement
    {
        if (mp[s[i]] < mp[s[i + 1]])
            res -= mp[s[i]];
        else
            res += mp[s[i]];
    }

    return res;
}

string intToRoman(int num)
{

    int numbers[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    string res;

    for (int i = 0; i < 13; i++)
    {
        while (num >= numbers[i])
        {
            num -= numbers[i];
            res += romans[i];
        }
    }

    return res;
}

int main()
{

    return 0;
}