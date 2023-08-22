class Solution {
public:
    string convertToTitle(int cn) {
        
        string ans="";
        while(cn)
        {
            if(cn<26)
            {
                ans+=(('A'+cn)-1);
                break;
            }
            if(cn%26==0)
            {
                ans+='Z';
                cn--;
                cn=cn/26;
            }
            else
            {
                ans+=('A'+(cn%26-1));
                cn=cn/26;
            }
                
          //  cout<<cn<<" "<<ans<<endl;
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};