class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        int n=s.length();
        
        vector<int> pi(n,0);
        
        int j=0;
        for(int i=1;i<n;i++)
        {
            if(s[i]==s[j])
            {
                pi[i]=j+1;
                j++;
            }
            else
            {
                int flag=0;
                j=(j-1>=0)?pi[j-1]:flag=1;
                
                while(j>=0 && flag==0)
                {
                    if(s[i]==s[j])
                    {
                        break;
                    }
                    else
                    {
                        j=(j-1>=0)?pi[j-1]:flag=1;
                        
                        if(flag==1)
                            break;
                    }
                }
                
                if(flag==0)
                {
                    pi[i]=j+1;
                    j++;
                }
                else
                {
                    pi[i]=0;
                    j=0;
                }
            }
        }
        
        for(auto &it:pi)
            cout<<it<<" ";
        cout<<endl;
        
        vector<int> pat;
        pat.push_back(pi[0]);
        
        for(int i=1;i<n;i++)
        {
            
            if(pi[i]>pat.back())
                pat.push_back(pi[i]);
            else
                break;
        }
        
        return pi[n-1]&&(pi[n-1]%(n-pi[n-1]))==0;
    }
};













