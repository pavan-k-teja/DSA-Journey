#include<bits/stdc++.h>
using namespace std;

//push, pop, top, isEmpty, isFull
class TwoStack
{
    int* arr;
    int max_cap;
    int top1;
    int top2;

public:
    TwoStack(int cap)
    {
        max_cap = cap;
        arr = new int[cap];
        top1 = -1;
        top2 = cap;
    }

    bool isEmpty1()
    {
        return top1==-1;
    }

    bool isEmpty2()
    {
        return top2==max_cap;
    }

    bool isFull()
    {
        return top1+1==top2;
    }

    bool push1(int val)
    {
        if(isFull())
            return false; //failure
        arr[++top1]=val;

        return true; //success
    }
    bool push2(int val)
    {
        if(isFull())
            return false; //failure
        arr[--top2]=val;
        
        return true; //success
    }

    int pop1()
    {
        if(isEmpty1())
            return INT_MIN;
        
        return arr[top1--];
    }
    int pop2()
    {
        if(isEmpty2())
            return INT_MIN;
        
        return arr[top2++];
    }

    int peek1()
    {
        if(isEmpty1())
            return INT_MIN;
        
        return arr[top1];
    }
    int peek2()
    {
        if(isEmpty2())
            return INT_MIN;
        
        return arr[top2];
    }
};

int main()
{
    int size = 5;
    TwoStack twoStack(size);

    cout<< twoStack.push1(1)<<"\n";
    cout<< twoStack.push2(1)<<"\n";
    cout<< twoStack.push1(2)<<"\n";
    cout<< twoStack.push2(2)<<"\n";
    cout<< twoStack.push1(3)<<"\n\n";

    cout<< twoStack.push1(4)<<"\n";
    cout<< twoStack.isEmpty1()<<"\n";
    cout<< twoStack.isEmpty2()<<"\n";
    cout<< twoStack.isFull()<<"\n\n";

    cout<< twoStack.pop1()<<"\n";
    cout<< twoStack.pop2()<<"\n";
    
    return 0;
}