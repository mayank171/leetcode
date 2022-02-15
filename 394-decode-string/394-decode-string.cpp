class Solution {
public:

    string check(string s,int &ind)
    {
        string res="";
        while(ind<s.length() && s[ind]!=']')
        {
            if(s[ind]>='0' && s[ind]<='9')
            {
                int k=0;
                while(ind<s.length() && s[ind]>='0' && s[ind]<='9')
                {
                    k=k*10+s[ind]-'0';
                    ind++;
                }
                ind++;
                
                string ans=check(s,ind);
                
                while(k--)
                {
                    res+=ans;
                }
                ind++;
            }
            else
            {
                res+=s[ind];
                ind++;
            }
            
        }
        
        return res;
    }
    
  
    
    string decodeString(string s) {
        
        
        int ind=0;
        
        string ans="";
        
        return check(s,ind);
        
        
        
    
    }
};