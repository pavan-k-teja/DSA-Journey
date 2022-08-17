// Leetcode-921

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        
        for(char c: s)
        {
            if(st.empty())
                st.push(c);
            else if(c == ')' && st.top()== '(')
                st.pop();
            else
                st.push(c);
        }
        return st.size();
    }
};

// no need to use stack as we have only one type of symbol

class Solution {
public:
    int minAddToMakeValid(string s) {
        int open_count = 0;
        int close_count = 0;
        for(auto i : s)
        {
            if(i == '(')
                open_count++;
            
            if(i == ')')
            {
                if(open_count > 0)
                    open_count--;

                else
                    close_count++;
            }
        }
        return close_count + open_count;
    }
};
