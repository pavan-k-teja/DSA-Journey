// CPP program to convert infix to prefix
#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c)
{
    return (c == '^' || c == '/' || c == '*' || c == '+' || c == '-' || c == '(' || c == ')');
}

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
            while (!st.empty() && precedence(c) <= precedence(st.top()))
            {
                if (c == '^' && st.top() == '^')
                    break;
                else
                {
                    result += st.top();
                    st.pop();
                }
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


string infixToPrefix(string infix)
{
	// Reverse infix
	reverse(infix.begin(), infix.end());

	// Replace ( with ) and vice versa
	for (int i = 0; i < infix.size(); i++)
    {
		if (infix[i] == '(')
			infix[i] = ')';
		else if (infix[i] == ')')
			infix[i] = '(';
	}

	string prefix = infixToPostfix(infix);

	// Reverse postfix
	reverse(prefix.begin(), prefix.end());

	return prefix;
}

// Driver code
int main()
{
	string s = ("x+y*z/w+u");
	cout << infixToPrefix(s) << std::endl;
	return 0;
}
