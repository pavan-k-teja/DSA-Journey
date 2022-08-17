// Leetcode-1021
#include<iostream>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string str) {
        // stack<char> s;
        
        string out="";
        
        int count = 0;
        for(char c : str)
        {
            if(c == '(')
            {
                if(count>0)
                    out+=c;
                count++;            
            }
            else
            {
                if(count>1)
                    out+=c;
                count--;
            }
                
        }
        return out;
    }
};