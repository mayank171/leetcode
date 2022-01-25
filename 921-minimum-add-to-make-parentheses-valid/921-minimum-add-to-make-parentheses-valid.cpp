class Solution {
public:
    int minAddToMakeValid(string s) {
        
        int l=s.length();
        
        stack<char> stk;
        
        for(int i=0;i<l;i++)
        {
            if(s[i]=='(')
            {
                 stk.push('(');
            }
            else
            {
                if(!stk.empty() && stk.top()=='(')
                {
                    stk.pop();
                }
                else
                {
                    stk.push(')');
                }
            }
        }
        
        return stk.size();
        
    }
};