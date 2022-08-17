#include <iostream>
#include <stack>
using namespace std;

bool isOperator(char c)
{
    return (c == '^' || c == '/' || c == '*' || c == '+' || c == '-');
}

string postfixToPrefix(string postfix)
{
    stack<string> s;

    for (int i = 0; i < postfix.size(); i++)
    {
        if (isOperator(postfix[i]))
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();

            string temp =  postfix[i] + op2 + op1;

            s.push(temp);
        }
        else
            s.push(string(1, postfix[i]));
    }

    return s.top();
}

// Driver Code
int main()
{
    string postfix = "ABC/-AK/L-*";
    cout << "Prefix : " << postfixToPrefix(postfix) << endl;
    return 0;
}
