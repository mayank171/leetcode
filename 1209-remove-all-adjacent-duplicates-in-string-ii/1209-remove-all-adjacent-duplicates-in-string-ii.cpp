class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        stack<pair<char,int>>  stk;
        
        int n=s.length();
        
        for(int i=0;i<n;i++)
        {
            if(!stk.empty() && stk.top().first==s[i])
            {
                if(stk.top().second==k-1)
                {
                   // cout<<stk.top().first<<"popped"<<endl;
                    stk.pop();
                }
                else
                {
                   // cout<<stk.top().first<<" "<<stk.top().second+1<<endl;
                    stk.top().second+=1;
                }
            }
            else
            {
                stk.push({s[i],1});
            }
        }
        
        string ans="";
        
        while(!stk.empty())
        {
            char ch=stk.top().first;
            int x=stk.top().second;
            stk.pop();
            
            while(x--)
            {
                ans+=ch;
            }
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        
    }
};