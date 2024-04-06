class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        int n=s.length();
        
        stack<pair<char,int>> stk;
        
        string ans="";
        set<int> st;
        int ct=0;
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                stk.push({s[i],i});
            }
            else if(s[i]==')')
            {
                if(!stk.empty() && stk.top().first=='(')
                {
                    stk.pop();
                }
                else
                {
                    ct++;
                    st.insert(i);
                }
            }
        }
        
        while(!stk.empty())
        {
            st.insert(stk.top().second);
            stk.pop();
        }
        
        for(int i=0;i<n;i++)
        {
            if(st.find(i)==st.end())
            {
                ans+=s[i];
            }
        }
        
        return ans;
        
    }
};