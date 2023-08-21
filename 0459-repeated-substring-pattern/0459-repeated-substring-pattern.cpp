class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        int n=s.length();
        
        if(n==1)
            return false;
        
        int j=0;
        vector<int> lps(n,0);
        for(int i=1;i<n;i++)
        {
            if(s[i]==s[j])
            {
                lps[i]=j+1;
                j++;
            }
            else
            {
                int flag=0;
                j=(j-1>=0)?lps[j-1]:flag=1;
                
                while(j>=0 && flag==0)
                {
                    if(s[i]==s[j])
                    {
                        break;
                    }
                    else
                    {
                        j=(j-1>=0)?lps[j-1]:flag=1;
                        
                        if(flag==1)
                            break;
                    }
                }
                
                if(flag==1)
                {
                    j=0;
                }
                else
                {
                    lps[i]=j+1;
                    j++;
                }
            }
        }
        
        for(auto &it:lps)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        
        return lps[n-1]&&(lps[n-1]%(n-lps[n-1])==0);
    }
};




