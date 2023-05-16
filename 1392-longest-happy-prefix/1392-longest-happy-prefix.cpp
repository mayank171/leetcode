class Solution {
public:
    string longestPrefix(string s) {
        
        int n=s.length();
        
        if(n==1)
            return "";
        
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
        
        if(pi[n-1]==0)
            return "";
        
        string ans="";
        int cur=pi[n-1];
        for(int i=0;i<n;i++)
        {
            ans+=s[i];
            cur--;
            if(cur==0)
                break;
        }
        
        //reverse(ans.begin(),ans.end());
        
        // if(ans.size()==1)
        //     return "";
        
        return ans;
        
    }
};