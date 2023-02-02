#include <bits/stdc++.h>
using namespace std;

// Function to return precedence of operators
int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    return 0;
}

bool isOperator(char c)
{
    return (c == '^' || c == '/' || c == '*' || c == '+' || c == '-' || c == '(' || c == ')');
}

string infixToPostfix(string s)
{
    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        if (!isOperator(c))
            result += c;

        else if (c == '(')
            st.push('(');

        else if (c == ')')
        {
            while (st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }

        else
        {
            while (!st.empty() && precedence(st.top()) >= precedence(c))
            {
                if (c == '^' && st.top() == '^')
                    break;
                
                result += st.top();
                st.pop();
                
            }
            st.push(c);
        }
    }

    // Pop all the remaining elements from the stack
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    return result;
}

int main()
{
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    string result = infixToPostfix(exp);
    cout << result << endl;
    return 0;
}
