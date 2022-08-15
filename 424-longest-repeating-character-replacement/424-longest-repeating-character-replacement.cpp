class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int n=s.length();
        
        
        if(k==0)
        {
            int maxi=0;
            int ct=1;
            for(int i=0;i<n-1;i++)
            {
                if(s[i]==s[i+1])
                {
                    ct++;
                }
                else
                {
                    maxi=max(maxi,ct);
                    ct=1;
                }
            }
            maxi=max(maxi,ct);
            
            return maxi;
        }
        
        
        
        set<char> st;
        
        for(auto &it:s)
        {
            st.insert(it);
        }
        
        
        int ans=0;
        for(auto &it:st)
        {
            int i=-1;
            int j=-1;
            int maxi=0;
            int K=k;
            
            while(true)
            {
                int flag1=0;
                int flag2=0;
                
                while(i<n-1)
                {
                    flag1=1;
                    i++;
                    if(s[i]!=it)
                    {
                        if(K==0)
                        {
                            i--;
                            break;
                        }
                        else
                        {
                            K--;
                        }
                    }
                    
                }
                
                while(j<i)
                {
                    
                    flag2=1;
                    maxi=max(maxi,i-j);
                    j++;
                    if(s[j]!=it)
                    {
                        K++;
                        break;
                    }
                }
                
                if(flag1==0 && flag2==0)
                    break;
            }
            
            ans=max(ans,maxi);
        }
        
        return ans;
        
    }
};