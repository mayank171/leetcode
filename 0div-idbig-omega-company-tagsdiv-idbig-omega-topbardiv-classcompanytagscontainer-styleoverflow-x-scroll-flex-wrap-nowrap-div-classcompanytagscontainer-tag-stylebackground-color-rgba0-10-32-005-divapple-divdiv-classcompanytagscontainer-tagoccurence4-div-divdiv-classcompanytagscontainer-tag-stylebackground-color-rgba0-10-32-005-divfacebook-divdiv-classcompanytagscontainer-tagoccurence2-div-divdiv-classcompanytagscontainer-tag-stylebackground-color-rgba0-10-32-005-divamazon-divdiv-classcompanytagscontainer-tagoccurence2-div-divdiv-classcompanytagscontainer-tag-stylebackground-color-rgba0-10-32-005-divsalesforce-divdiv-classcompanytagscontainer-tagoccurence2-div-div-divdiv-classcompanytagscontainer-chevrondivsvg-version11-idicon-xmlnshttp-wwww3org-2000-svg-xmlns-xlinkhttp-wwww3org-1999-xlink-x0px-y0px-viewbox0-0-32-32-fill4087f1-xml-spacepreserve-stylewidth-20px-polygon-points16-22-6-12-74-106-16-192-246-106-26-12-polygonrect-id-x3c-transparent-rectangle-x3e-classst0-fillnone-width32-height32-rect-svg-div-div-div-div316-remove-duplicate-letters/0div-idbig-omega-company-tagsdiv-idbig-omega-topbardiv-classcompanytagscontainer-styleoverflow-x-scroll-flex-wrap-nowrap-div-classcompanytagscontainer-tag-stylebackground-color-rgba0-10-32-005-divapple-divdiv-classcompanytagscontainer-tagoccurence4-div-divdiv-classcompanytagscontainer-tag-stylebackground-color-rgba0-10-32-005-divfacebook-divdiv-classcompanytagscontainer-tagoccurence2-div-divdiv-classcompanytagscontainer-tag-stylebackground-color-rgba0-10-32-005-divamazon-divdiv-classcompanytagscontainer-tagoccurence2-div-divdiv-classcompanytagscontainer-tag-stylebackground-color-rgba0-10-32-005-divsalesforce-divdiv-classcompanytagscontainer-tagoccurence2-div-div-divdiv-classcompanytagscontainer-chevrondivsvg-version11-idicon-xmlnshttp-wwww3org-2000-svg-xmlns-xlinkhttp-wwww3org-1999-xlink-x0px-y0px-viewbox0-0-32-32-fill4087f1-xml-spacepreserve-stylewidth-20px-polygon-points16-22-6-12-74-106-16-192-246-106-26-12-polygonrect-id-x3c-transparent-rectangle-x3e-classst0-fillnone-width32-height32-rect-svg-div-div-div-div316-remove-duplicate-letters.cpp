class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        int l=s.length();
        
        stack<char> stk;
        string ans="";
        map<char,int> mp;
        set<int> st;
        
        for(int i=0;i<l;i++)
        {
            mp[s[i]]++;
        }
        
        for(int i=0;i<l;i++)
        {
            if(stk.size()==0)
            {
                if(mp[s[i]]>0 && st.find(s[i])==st.end())
                {
                    stk.push(s[i]);
                    mp[s[i]]--;
                    st.insert(s[i]);
                }
            }
            else if(stk.top()>s[i] && st.find(s[i])==st.end())
            {
                if(mp[stk.top()]==0)
                {
                    stk.push(s[i]);
                    st.insert(s[i]);
                    mp[s[i]]--;
                }
                else
                {
                    while(!stk.empty() && stk.top()>=s[i] && mp[stk.top()]>0)
                    {
                        st.erase(stk.top());
                        stk.pop();
                    }
                    stk.push(s[i]);
                    mp[s[i]]--;
                    st.insert(s[i]);
                }
            }
            else if(stk.top()<s[i] && st.find(s[i])==st.end())
            {
                stk.push(s[i]);
                st.insert(s[i]);
                mp[s[i]]--;
            }
            else if(st.find(s[i])!=st.end())
            {
                mp[s[i]]--;
            }
        }
        
        while(!stk.empty())
        {
            ans+=stk.top();
            stk.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};