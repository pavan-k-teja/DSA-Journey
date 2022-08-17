#include <iostream>
#include <stack>
#include <vector>
#include <climits>
using namespace std;

/* A special stack having peek() pop() and push() along with additional getMin() that
 * returns minimum value in a stack without using extra space and all operations in O(1) time */

struct MyStack
{
    stack<int> s;
    int minEle;

    int getMin()
    {
        if (s.empty())
            return INT_MIN;
        else
            return minEle;
    }

    int peek()
    {
        if (s.empty())
            return INT_MIN;
        
        int top = s.top();
        return (minEle > top) ? minEle : top;
    }

    void pop()
    {
        if (s.empty())
            return;

        int top = s.top();
        s.pop();

        if (top < minEle)
            minEle = 2 * minEle - top;
    }

    void push(int x)
    {
        if (s.empty())
        {
            minEle = x;
            s.push(x);
            cout << "Number Inserted: " << x << "\n";
            return;
        }
        else if (x < minEle)
        {
            s.push(2 * x - minEle);
            minEle = x;
        }
        else
            s.push(x);

        cout << "Number Inserted: " << x << "\n";
    }
};

int main()
{
    MyStack s;
    s.push(3);
    s.push(5);
    s.getMin();
    s.push(2);
    s.push(1);
    s.getMin();
    s.pop();
    s.getMin();
    s.pop();
    s.peek();

    return 0;
}
