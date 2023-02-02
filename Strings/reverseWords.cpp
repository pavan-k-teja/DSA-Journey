#include<bits/stdc++.h>
using namespace std;


/*
    Time Complexity  = O(N)
    Space Complexity = O(N)

    Where N is the size of the string.
*/

string reverseString(string str)
{
    string ans;
    int end = str.size() - 1;

    while (end >= 0)
    {
        if (str[end] == ' ')
            end--;
        else
        {
            if (ans.size() > 0)
                ans.push_back(' ');

            int start = end;
            while (start >= 0 && str[start] != ' ')
                start--;

            ans.append(str.substr(start + 1, end - start));
            end = start;
        }
    }

    return ans;
}