class Solution {
public:
    string minWindow(string s, string t) {
        
        if(s.length()<t.length())
            return "";
        
        int n1=s.length();
        
        map<char,int> mp1;
        
        map<char,int> mp2;
        for(int i=0;i<t.length();i++)
        {
           // mp1[t[i]]++;
            mp2[t[i]]++;
        }
        
        int bal=0;
        
        int i=-1;
        int j=-1;
        
        int ans=1e9;
        
        string res="";
        int l=-1;
        int r=-1;
        
        while(true)
        {
            int flag1=0;
            int flag2=0;
            while(i<n1-1)
            {
                flag1=1;
                i++;
                //mp2[s[i]]++;
                
                if(mp2.find(s[i])==mp2.end())
                {
                    mp1[s[i]]++;
                }
                else
                {
                    if(mp2[s[i]]<mp1[s[i]]+1)
                    {
                        mp1[s[i]]++;
                        continue;
                    }   
                    mp1[s[i]]++;
                    bal++;
                }
                
                if(bal==t.length())
                    break;
            }
            
           // cout<<i<<" - "<<j<<endl;
            while(j<i && bal==t.length())
            {
                flag2=1;
                if(i-j<=ans)
                {
                   
                    ans=i-j;
                    l=j+1;
                    r=i;
             //       cout<<"l"<<l<<" r"<<r<<endl;
                }
                j++;
                mp1[s[j]]--;
                
                if(mp2.find(s[j])!=mp2.end() && mp1[s[j]]<mp2[s[j]])
                {
                    bal--;    
            //        cout<<s[j]<<" "<<mp1[s[j]]<<" "<<mp2[s[j]]<<endl;
                }
                
            }
            
            
            if(flag1==0 && flag2==0)
                break;
        }
        
      //  cout<<l<<" "<<r<<endl;
        
        if(l==-1 || r==-1)
            return "";
        
        res=s.substr(l,r-l+1);
        
        return res;
    }
};