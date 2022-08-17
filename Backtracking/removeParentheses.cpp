#include <bits/stdc++.h>
using namespace std;

int getMin(string str)
{
    stack<char> s;
    for (char c : str)
    {
        if (s.empty() || c == '(' || (s.top() == ')' && c == ')'))
            s.push(c);
        else if (s.top() == '(')
            s.pop();
    }

    return s.size();
}
void removeParentheses(string s, int rem, unordered_set<string> &us)
{
    if (rem == 0)
    {
        if (getMin(s) == 0)
        {
            if (us.find(s) == us.end())
                us.insert(s);
        }
        return;
    }

    for (int i = 0; i < s.size(); i++)
    {
        string temp = s;
        temp.erase(temp.begin() + i);
        removeParentheses(temp, rem - 1, us);
    }
}

int main()
{

    string p = "()()(()))()";
    unordered_set<string> us;
    int removals = getMin(p);
    removeParentheses(p, removals, us);

    for(auto &ele : us)
        cout << ele << "\n";

    return 0;
}