class Solution {
public:
   
    
    string minWindow(string s, string t) {
        
        int n=s.length();
        int m=t.length();
        
        map<char,int> mp2;
        
        for(int i=0;i<m;i++)
        {
            mp2[t[i]]++;
        }
        
        map<char,int> mp1;
        int i=-1;
        int j=-1;
        int mct=0;
        int dmct=m;
        
        string ans="";
        
        while(true)
        {
            int flag1=0;
            int flag2=0;
            while(i<n-1 && mct<dmct)
            {
                flag1=1;
                i++;
                mp1[s[i]]++;
                if(mp1[s[i]]<=mp2[s[i]])
                {
                    mct++;
                }
            }
            
            while(j<i && mct==dmct)
            {
                flag2=1;
                string str=s.substr(j+1,i-j);
                
                if(ans.length()==0 || str.length()<ans.length())
                    ans=str;
                j++;
                char ch=s[j];
                if(mp1[ch]==1)
                    mp1.erase(ch);
                else
                {
                    mp1[ch]--;
                }
                
                if(mp1[ch]<mp2[ch])
                {
                    mct--;
                }
            }
            
            if(flag1==0 && flag2==0)
                break;
        }
        
        return ans;
    }
};