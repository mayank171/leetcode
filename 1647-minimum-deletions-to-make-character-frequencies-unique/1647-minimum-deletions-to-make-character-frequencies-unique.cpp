class Solution {
public:
    int minDeletions(string s) {
        
        map<char,int> mp;
        
        int n=s.length();
        
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
        }
        
        set<int> st;
        int ans=0;
        
        for(auto &it:mp)
        {
            char ch=it.first;
            int ct=it.second;
            
            if(st.find(ct)==st.end())
            {
                st.insert(ct);
            }
            else
            {
                while(st.find(ct)!=st.end())
                {
                    ans+=1;
                    ct--;
                }
                
                if(ct!=0)
                   st.insert(ct);
            }
        }
        
        return ans;
    }
};




















