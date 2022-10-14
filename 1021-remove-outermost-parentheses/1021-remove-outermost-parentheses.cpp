class Solution {
public:
    string removeOuterParentheses(string s) {
        
        int n=s.length();
        
        string ans="";
        stack<char> stk;
        
        for(int i=0;i<n;i++)
        {
            if(stk.empty())
            {
                stk.push(s[i]);
            }
            else if(s[i]=='(')
            {
                stk.push(s[i]);
                ans+=s[i];
            }
            else if(s[i]==')' && stk.size()==1)
            {
                stk.pop();
                continue;
            }
            else
            {
                stk.pop();
                ans+=s[i];
            }
        }
        
        return ans;
    }
};