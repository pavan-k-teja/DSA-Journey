// Leetcode-1190

class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        string out = "";
        
        for(char c:s)
        {
            if(c == '(')
                st.push('(');
            else if(c !=')')
                st.push(c);
            else
            {
                while(st.top()!='(')
                {
                    out+=st.top();
                    st.pop();
                }
                st.pop();
                for(char o : out)
                {
                    st.push(o);
                }
                out="";
            }
        }
        
        while(!st.empty())
        {
            out+=st.top();
            st.pop();
        }
        reverse(out.begin(), out.end());
        return out;
    }
};