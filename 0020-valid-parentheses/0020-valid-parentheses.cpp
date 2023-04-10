class Solution {
public:
    bool isValid(string s) {
        
        int n=s.length();
        
        stack<char> stk;
        for(int i=0;i<n;i++)
        {
            
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
            {
                stk.push(s[i]);
            }
            else if((s[i]==')' || s[i]=='}' || s[i]==']') && stk.empty())
            {
                return false;
            }
            else if(s[i]==')' && stk.top()=='(')
            {
                stk.pop();
            }
            else if(s[i]==']' && stk.top()=='[')
            {
                stk.pop();
            }
            else if(s[i]=='}' && stk.top()=='{')
            {
                stk.pop();
            }
            else
            {
                return false;
            }
            
        }
        
        if(stk.size()>0)
            return false;
        
        return true;
        
    }
};