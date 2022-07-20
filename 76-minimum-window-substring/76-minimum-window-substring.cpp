class Solution {
public:
   
    
    string minWindow(string s, string t) {
        
        int n=s.length();
        int m=t.length();
        
        map<char,int> mp2;
        
        for(auto &it:t)
            mp2[it]++;
        
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
                i++;
                mp1[s[i]]++;
                
                if(mp1[s[i]]<=mp2[s[i]])
                    mct++;
                flag1=1;
            }
            
            int ind=0;
            while(j<i && mct==dmct)
            {
               // cout<<s<<endl;
                string cur=s.substr(j+1,i-j);
              //  cout<<s.substr(1,2)<<endl;
                //cout<<i<<" "<<j<<" "<<cur<<endl;
                if(ans.length()==0 || cur.length()<ans.length())
                    ans=cur;
                
                j++;
                char ch=s[j];
                if(mp1[ch]==1)
                    mp1.erase(ch);
                else
                    mp1[ch]--;
                
                if(mp1[ch]<mp2[ch])
                    mct--;
                flag2=1;
                ind++;
            }
            
            if(flag1==0 && flag2==0)
                break;
        }
        
        return ans;
    }
};