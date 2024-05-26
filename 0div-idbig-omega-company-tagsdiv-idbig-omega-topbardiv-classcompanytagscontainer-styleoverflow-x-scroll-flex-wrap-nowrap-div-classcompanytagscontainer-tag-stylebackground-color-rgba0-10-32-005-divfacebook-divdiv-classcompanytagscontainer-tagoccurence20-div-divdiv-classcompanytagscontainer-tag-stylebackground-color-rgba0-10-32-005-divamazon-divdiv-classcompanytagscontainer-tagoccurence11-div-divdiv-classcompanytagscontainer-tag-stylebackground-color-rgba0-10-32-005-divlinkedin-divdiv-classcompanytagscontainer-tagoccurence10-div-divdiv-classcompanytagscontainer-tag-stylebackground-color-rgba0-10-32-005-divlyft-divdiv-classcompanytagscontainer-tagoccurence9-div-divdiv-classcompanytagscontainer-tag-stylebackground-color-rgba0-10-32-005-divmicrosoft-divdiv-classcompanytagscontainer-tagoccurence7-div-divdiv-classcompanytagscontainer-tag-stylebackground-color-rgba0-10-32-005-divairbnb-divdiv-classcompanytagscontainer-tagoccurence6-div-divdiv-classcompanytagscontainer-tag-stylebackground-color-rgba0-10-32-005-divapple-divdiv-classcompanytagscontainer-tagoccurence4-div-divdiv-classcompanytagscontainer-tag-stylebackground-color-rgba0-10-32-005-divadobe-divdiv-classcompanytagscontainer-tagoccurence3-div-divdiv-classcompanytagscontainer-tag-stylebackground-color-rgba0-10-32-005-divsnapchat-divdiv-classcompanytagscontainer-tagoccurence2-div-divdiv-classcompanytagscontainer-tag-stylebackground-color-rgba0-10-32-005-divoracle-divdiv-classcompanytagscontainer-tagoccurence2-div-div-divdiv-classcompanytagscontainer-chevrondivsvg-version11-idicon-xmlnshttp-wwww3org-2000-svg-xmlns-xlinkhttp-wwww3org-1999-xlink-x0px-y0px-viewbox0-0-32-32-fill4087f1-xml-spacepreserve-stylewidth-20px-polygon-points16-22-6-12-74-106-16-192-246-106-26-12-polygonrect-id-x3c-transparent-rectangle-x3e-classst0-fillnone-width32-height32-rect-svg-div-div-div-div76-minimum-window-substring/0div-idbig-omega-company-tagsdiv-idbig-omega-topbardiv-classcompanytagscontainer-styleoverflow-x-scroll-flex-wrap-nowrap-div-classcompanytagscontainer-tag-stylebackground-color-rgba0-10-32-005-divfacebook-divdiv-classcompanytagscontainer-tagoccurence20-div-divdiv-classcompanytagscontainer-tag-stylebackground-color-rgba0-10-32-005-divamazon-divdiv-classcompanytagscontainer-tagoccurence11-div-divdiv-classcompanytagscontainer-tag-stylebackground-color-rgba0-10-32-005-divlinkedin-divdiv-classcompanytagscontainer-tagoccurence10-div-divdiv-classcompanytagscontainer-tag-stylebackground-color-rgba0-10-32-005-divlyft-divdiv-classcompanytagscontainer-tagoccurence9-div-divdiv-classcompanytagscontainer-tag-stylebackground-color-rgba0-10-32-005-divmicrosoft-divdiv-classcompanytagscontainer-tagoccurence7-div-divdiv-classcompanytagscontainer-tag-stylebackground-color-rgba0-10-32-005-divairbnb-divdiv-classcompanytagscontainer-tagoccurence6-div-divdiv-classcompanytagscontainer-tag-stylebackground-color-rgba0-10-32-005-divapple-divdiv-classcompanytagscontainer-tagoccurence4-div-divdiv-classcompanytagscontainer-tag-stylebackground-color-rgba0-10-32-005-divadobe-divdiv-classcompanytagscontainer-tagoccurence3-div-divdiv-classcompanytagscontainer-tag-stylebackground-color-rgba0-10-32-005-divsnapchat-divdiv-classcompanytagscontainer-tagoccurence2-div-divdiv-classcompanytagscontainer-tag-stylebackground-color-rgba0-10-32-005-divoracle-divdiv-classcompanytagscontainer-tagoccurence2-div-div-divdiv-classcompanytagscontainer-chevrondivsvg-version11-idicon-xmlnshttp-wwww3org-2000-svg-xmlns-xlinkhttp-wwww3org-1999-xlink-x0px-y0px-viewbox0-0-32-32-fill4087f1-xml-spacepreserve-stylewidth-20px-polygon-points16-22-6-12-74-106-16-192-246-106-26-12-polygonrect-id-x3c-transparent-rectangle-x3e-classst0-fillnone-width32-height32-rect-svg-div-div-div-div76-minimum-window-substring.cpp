class Solution {
public:
    string minWindow(string s, string t) {
        
        int n1=s.length();
        int n2=t.length();
        
        if(n1<n2)
            return "";
        
        int cur=0;
        int req=n2;
        
        map<int,int> mp1;
        map<int,int> mp2;
        
        for(int i=0;i<n2;i++)
        {
            mp2[t[i]]++;
        }
        
        int i=-1;
        int j=-1;
        int ans=1e8;
        int l=0;
        int r=-1;
        
        while(true)
        {
            int flag1=0;
            int flag2=0;
            
            while(i<n1)
            {
                flag1=1;
                i++;
                mp1[s[i]]++;
                if(mp1[s[i]]<=mp2[s[i]])
                {
                    cur++;
                }
                
                if(cur==req)
                {
                    break;
                }
            }
            
            while(j<i && cur==req)
            {
                if(ans>=abs(i-j))
                {
                    cout<<j+1<<" "<<i<<endl;
                    l=j+1;
                    r=i;
                    ans=abs(i-j);
                }
                j++;
                flag2=1;
                mp1[s[j]]--;
                if(mp2[s[j]]>mp1[s[j]])
                {
                    cur--;
                }
            }
            
            if(flag1==0 && flag2==0)
                break;
        }
        
        string res="";
        for(int k=l;k<=min(r,n1-1);k++)
        {
            res+=s[k];
        }
        
        return res;
    }
};