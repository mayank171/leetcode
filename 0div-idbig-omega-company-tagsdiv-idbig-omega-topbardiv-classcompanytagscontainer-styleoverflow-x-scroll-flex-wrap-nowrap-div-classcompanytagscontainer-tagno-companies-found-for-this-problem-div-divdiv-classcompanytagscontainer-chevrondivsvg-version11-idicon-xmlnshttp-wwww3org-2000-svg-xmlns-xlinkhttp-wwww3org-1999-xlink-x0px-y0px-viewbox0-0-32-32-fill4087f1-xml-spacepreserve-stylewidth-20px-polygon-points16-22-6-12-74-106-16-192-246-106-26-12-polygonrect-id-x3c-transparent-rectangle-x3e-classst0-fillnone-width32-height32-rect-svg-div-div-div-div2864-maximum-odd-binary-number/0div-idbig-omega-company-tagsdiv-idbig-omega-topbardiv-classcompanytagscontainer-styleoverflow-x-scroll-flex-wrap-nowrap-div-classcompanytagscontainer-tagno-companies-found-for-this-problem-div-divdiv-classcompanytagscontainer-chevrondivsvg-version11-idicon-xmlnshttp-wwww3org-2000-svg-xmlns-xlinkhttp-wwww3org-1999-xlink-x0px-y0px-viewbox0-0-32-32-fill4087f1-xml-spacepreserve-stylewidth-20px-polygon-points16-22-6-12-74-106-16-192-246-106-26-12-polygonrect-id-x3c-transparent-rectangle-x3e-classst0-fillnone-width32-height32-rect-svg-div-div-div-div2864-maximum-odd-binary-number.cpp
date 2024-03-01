class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        
        int n=s.length();
        int zeros=0;
        int ones=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')
                zeros++;
            else
                ones++;
        }
        
        string ans="";
        
        ans+='1';
        ones--;
        
        while(zeros--)
        {
            ans+='0';
        }
        
        while(ones--)
        {
            ans+='1';   
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};