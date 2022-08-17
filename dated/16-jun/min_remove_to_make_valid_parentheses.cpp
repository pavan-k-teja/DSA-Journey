//Leetcode-1249

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        int count =0;
        //from left->right
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
                count++;
            else if(s[i]==')')
            {
                if(count==0)
                    s[i]=' ';
                else
                    count--;
            }
        }
        
        count =0;
        //from right->left
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i]==')')
                count++;
            else if(s[i]=='(')
            {
                if(count==0)
                    s[i]=' ';
                else
                    count--;
            }
        }
        string ans;
        for(char c:s)
            if(c!=' ')
                ans+=c;
        return ans;
    }
};