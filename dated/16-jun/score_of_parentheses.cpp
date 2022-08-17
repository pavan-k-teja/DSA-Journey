class Solution {
public:
    int scoreOfParentheses(string s) 
    {
        stack<int> st;
        
        for(char c : s)
        {
            if( c == '(')
                st.push(0);
            else
            {
                if(st.top() == 0)
                {
                    st.pop();
                    st.push(1);
                }
                else
                {
                    int sum = 0;
                    while(st.top() != 0)
                    {
                        sum += st.top();
                        st.pop();
                    }
                    sum *= 2;
                    st.pop();
                    st.push(sum);
                }
            }
        }
        int sum = 0;
        while(!st.empty())
        {
            sum += st.top();
            st.pop();
        }
        return sum;
        
    }
};