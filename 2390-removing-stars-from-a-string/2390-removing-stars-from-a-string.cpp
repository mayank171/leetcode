class Solution {
public:
    string removeStars(string s) {
        
        stack<char> stk;
        
        int n=s.length();
        
        for(int i=0;i<n;i++)
        {
            if(s[i]!='*')
            {
                stk.push(s[i]);
            }
            else
            {
                stk.pop();
            }
        }
        
        string ans="";
        while(!stk.empty())
        {
            ans.push_back(stk.top());
            stk.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        
    }
};