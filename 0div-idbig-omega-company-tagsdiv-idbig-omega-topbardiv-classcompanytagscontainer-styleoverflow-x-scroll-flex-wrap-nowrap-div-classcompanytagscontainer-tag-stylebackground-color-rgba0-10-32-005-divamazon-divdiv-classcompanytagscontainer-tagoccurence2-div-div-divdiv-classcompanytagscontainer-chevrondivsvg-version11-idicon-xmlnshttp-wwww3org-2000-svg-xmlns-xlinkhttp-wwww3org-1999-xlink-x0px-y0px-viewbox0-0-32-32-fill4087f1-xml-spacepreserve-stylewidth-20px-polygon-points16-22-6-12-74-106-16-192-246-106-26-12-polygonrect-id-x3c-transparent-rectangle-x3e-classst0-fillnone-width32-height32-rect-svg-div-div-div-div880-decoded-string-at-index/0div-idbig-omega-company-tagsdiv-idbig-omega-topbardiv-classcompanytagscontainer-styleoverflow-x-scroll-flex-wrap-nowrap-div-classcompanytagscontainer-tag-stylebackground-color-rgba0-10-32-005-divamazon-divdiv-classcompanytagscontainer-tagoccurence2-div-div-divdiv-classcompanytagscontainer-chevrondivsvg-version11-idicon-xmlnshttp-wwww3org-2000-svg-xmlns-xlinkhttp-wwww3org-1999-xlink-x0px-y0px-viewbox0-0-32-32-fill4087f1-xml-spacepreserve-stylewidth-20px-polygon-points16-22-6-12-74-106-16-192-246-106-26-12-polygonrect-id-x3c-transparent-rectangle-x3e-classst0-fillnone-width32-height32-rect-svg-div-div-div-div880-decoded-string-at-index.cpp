class Solution {
public:
    string decodeAtIndex(string s, int k) {
        
        long long ct=0;
        int n=s.length();
        
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]>='0' && s[i]<='9')
            {
                ct=(ct*1ll*(s[i]-'0'));
            }
            else
            {
                ct++;
            }
        }
        
        for(int i=n-1;i>=0;i--)
        {
            k%=ct;
            if(s[i]>='a' && s[i]<='z')
            {
                if(k==ct || k==0)
                {
                    string ans="";
                    ans+=s[i];
                    return ans;
                }
            }
            
            if(s[i]>='0' && s[i]<='9')
            {
                ct/=(s[i]-'0');  
            }
            else
            {
                ct--;
            }
        }
        
        return "";
    }
};