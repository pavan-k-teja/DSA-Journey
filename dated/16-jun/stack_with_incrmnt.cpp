// Leetcode-1381
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class CustomStack {
    int max_size;
    int curr_size=0;
    vector<int > value;
    vector<int > index;
public:
    CustomStack(int maxSize) {
        max_size = maxSize;
        curr_size = 0;
        for(int i=0;i<maxSize;i++)
        {
            value.push_back(-1);
            index.push_back(0);
        }
    }
    
    void push(int x) {
        if(curr_size == max_size)
            return;
        curr_size++;
        value[curr_size - 1] = x;
        index[curr_size - 1] = 0;
    }
    
    int pop() {
        if(curr_size ==0)
            return -1;
        int popped = value[curr_size -1] + index[curr_size -1];
        index[curr_size - 2] += index[curr_size -1];
        value[curr_size -1] = -1;
        index[curr_size -1] = 0;
        curr_size--;
        
        return popped;
    }
    
    void increment(int k, int val) {
        k = min(k, curr_size);
        index[k-1] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */

int main()
{

    return 0;
}