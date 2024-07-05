class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        int n1=s.length();
        int n2=p.length();
        
        map<char,int> mp1;
        
        for(int i=0;i<n2;i++)
        {
            mp1[p[i]]++;
        }
        
        int ct=0;
        
        
        map<char,int> mp2;
        
        for(int i=0;i<n2;i++)
        {
            mp2[s[i]]++;
        }
        
        
        vector<int> ans;
        int flag=0;
        int match=0;
        for(auto &it:mp1)
        {
            if(mp2[it.first]>it.second)
            {
                flag=1;
                match+=it.second;
               // break;
            }   
            else if(mp2[it.first]==it.second)
            {
                match+=it.second;
            }
            else if(mp2[it.first]<it.second)
            {
                match+=mp2[it.first];
                flag=1;
            }
        }
        
        if(flag==0)
            ans.push_back(0);
        
        cout<<match<<endl;
        
        int i=n2-1;
        int j=-1;
        
        while(j<i && i<n1)
        {
            j++;
            if(mp2[s[j]]-1<mp1[s[j]])
                match--;
            mp2[s[j]]--;
            i++;
            mp2[s[i]]++;
            if(mp2[s[i]]<=mp1[s[i]])
                match++;
            
            if(match==n2)
                ans.push_back(j+1);
        }
        
        
        return ans;
    }
};