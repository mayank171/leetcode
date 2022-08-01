class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        int l1=s.length();
        int l2=p.length();
        map<char,int> mp;
        
        for(int i=0;i<l2;i++)
        {
            mp[p[i]]++;
        }
        
        int i=-1;
        int j=-1;
        map<char,int> mp1;
        
        vector<int> ans;
        
        while(true)
        {
         //   cout<<i<<" "<<j<<endl;
            while(i<l1-1)
            {
                i++;
                mp1[s[i]]++;
                
                if(i-j==l2)
                {
       
                    break;
                }
            }
            
            
            int flag=0;
            for(auto &it:mp1)
            {
                if(it.second!=mp[it.first])
                {
                    flag=1;
                    break;
                }
            }
            
            if(flag==0)
            {
                ans.push_back(j+1);
            }
            
            j++;
            mp1[s[j]]--;
            if(mp1[s[j]]==0)
                mp1.erase(s[j]);
            
            if(i==l1-1 && i-j<l2)
                break;
            
        }
        
        return ans;
        
    }
};