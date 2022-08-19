class Solution {
public:
    int countBinarySubstrings(string s) {
        
        int n=s.length();
        
        int zero=0;
        int one=0;
        
//         char ch=s[0];
//         int ind=0;
//         for(int i=0;i<n;i++)
//         {
//             if(s[i]==ch)
//                 ind=i;
//             else
//                 break;
//         }
        
        int ct=1;
        int ans=0;
        int flag=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0' && flag==0)
            {
                if(i-1>=0 && s[i-1]=='1')
                {
                    zero=0;
                }
                
                if(one>0 && zero<one)
                    ans++;
                
                zero++;
            }
            else if(s[i]=='1' && flag==0)
            {
                if(i-1>=0 && s[i-1]=='0')
                {
                    one=0;
                }
                
                if(zero>0 && one<zero)
                    ans++;
                
                one++;
            }
            
        }
        
        return ans;
        
    }
};