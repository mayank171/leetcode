class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int l=s.length();
        
        vector<int> v(26,-1);
        
        for(int i=0;i<l;i++)
        {
            v[s[i]-'a']=i;
        }
        
        // for(auto &it:v)
        // {
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        
        vector<int> first(26,-1);
        
        for(int i=0;i<l;i++)
        {
            if(first[s[i]-'a']==-1)
            {
                first[s[i]-'a']=i;
            }
        }
        
        // for(auto &it:first)
        // {
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        
        
        map<char,pair<int,int>> mp;
        
        for(int i=0;i<26;i++)
        {
            if(v[i]!=-1 && first[i]!=-1)
            {
                mp[i+'a']={first[i],v[i]};
            }
        }
        
//         for(auto &it:mp)
//         {
//             cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<endl;
//         }
        
        int ans=0;
        for(auto &it:mp)
        {
            int x=it.second.first;
            int y=it.second.second;
            set<int> st;
            for(int i=x+1;i<y;i++)
                st.insert(s[i]);
            ans+=st.size();
        }
        
        return ans;
    }
};