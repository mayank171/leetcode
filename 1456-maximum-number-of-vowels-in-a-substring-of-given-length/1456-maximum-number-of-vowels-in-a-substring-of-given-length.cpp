class Solution {
public:
    
    bool isVowel(char ch)
    {
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
            return true;
        return false;
    }
    
    int maxVowels(string s, int k) {
        
        int n=s.length();
        int maxi=0;
        
        int i=-1;
        int j=-1;
        
        multiset<char> st;
        int v=0;
        int ans=0;
        
        
        while(true)
        {
            int flag1=0;
            int flag2=0;
            
            while(i<n-1)
            {
                flag1=1;
                i++;
                
                if(st.size()<k)
                {
                   // cout<<s[i]<<endl;
                    st.insert(s[i]);
                    if(isVowel(s[i]))
                        v++;
                }
                
                if(st.size()==k)
                {
                    break;
                }
            }
            
            while(j<i && st.size()==k)
            {
               // cout<<i<<" "<<v<<endl;
                flag2=1;
                ans=max(ans,v);
                j++;
                auto it=st.find(s[j]);
                if(it!=st.end())
                    st.erase(it);
                if(isVowel(s[j]))
                    v--;
            }
            
            if(flag1==0 && flag2==0)
                break;
        }
        
        return ans;
    }
};














