#include <iostream>
#include <stack>
using namespace std;

bool isOperator(char c)
{
    return (c == '^' || c == '/' || c == '*' || c == '+' || c == '-');
}

string prefixToInfix(string prefix)
{
    stack<string> s;

    // reading from right to left
    for (int i = prefix.size() - 1; i >= 0; i--)
    {
        if (isOperator(prefix[i]))
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();

            string temp = "(" + op1 + prefix[i] + op2 + ")";

            s.push(temp);
        }
        else
            s.push(string(1, prefix[i]));
    }

    return s.top();
}

// Driver Code
int main()
{
    string prefix = "*-A/BC-/AKL";
    cout << "Infix : " << prefixToInfix(prefix) << endl;
    return 0;
}
