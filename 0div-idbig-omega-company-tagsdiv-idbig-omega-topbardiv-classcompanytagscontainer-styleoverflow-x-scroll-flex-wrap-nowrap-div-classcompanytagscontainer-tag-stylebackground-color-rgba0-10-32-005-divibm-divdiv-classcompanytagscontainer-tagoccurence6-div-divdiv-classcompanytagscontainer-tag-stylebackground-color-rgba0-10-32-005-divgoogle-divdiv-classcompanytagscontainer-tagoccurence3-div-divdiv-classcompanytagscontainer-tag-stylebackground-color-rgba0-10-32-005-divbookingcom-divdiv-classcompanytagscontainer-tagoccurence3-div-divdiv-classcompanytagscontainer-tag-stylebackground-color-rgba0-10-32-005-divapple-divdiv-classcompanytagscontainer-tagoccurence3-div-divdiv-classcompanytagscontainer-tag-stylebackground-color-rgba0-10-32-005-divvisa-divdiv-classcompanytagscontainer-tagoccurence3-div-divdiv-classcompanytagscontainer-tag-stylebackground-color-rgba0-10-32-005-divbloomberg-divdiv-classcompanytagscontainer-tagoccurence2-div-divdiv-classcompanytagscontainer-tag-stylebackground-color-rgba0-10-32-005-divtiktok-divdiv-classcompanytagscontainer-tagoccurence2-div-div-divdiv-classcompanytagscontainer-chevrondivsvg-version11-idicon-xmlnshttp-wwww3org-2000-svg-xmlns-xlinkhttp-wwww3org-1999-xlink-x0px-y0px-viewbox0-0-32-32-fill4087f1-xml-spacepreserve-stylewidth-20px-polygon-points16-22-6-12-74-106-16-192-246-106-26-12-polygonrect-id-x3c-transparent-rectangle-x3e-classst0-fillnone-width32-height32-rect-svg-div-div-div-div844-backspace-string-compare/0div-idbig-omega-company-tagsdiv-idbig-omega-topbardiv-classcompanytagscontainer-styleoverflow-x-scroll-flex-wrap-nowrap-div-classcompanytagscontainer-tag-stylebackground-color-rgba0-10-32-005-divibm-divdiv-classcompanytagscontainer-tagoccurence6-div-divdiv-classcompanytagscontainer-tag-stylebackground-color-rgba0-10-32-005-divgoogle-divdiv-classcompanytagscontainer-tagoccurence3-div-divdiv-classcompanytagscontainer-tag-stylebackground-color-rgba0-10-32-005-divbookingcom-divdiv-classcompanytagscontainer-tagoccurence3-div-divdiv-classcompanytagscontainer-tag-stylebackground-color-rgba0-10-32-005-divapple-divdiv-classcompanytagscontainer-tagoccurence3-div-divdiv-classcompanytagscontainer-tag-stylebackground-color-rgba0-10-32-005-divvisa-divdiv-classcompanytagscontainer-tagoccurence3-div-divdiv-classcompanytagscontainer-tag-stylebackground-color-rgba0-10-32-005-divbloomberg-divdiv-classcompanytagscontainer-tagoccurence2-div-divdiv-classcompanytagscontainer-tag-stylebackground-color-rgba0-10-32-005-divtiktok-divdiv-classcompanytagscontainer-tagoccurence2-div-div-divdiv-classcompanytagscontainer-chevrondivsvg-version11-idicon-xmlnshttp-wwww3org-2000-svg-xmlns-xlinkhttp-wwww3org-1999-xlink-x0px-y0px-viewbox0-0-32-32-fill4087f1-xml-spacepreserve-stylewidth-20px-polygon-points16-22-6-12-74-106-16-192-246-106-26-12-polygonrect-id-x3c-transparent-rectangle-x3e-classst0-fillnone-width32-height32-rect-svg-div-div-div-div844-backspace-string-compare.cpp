class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        int n1=s.length();
        int n2=t.length();
        
        int ct1=0;
        int ct2=0;
        string s1="";
        string t1="";
        
        
        for(int i=0;i<min(n1,n2);i++)
        {
            if(s[i]==t[i] && s[i]!='#')
            {
                s1.push_back(s[i]);
                t1.push_back(t[i]);
            }
            else if(s[i]=='#' && t[i]=='#')
            {
                ct1--;
                if(s1.size()>0)
                    s1.pop_back();
                ct2--;
                if(t1.size()>0)
                    t1.pop_back();
                ct1=max(0,ct1);
                ct2=max(0,ct2);
            }
            else if(s[i]=='#' && t[i]!='#')
            {
                ct1--;
                ct1=max(0,ct1);
                if(s1.size()>0)
                    s1.pop_back();
                ct2++;
                t1.push_back(t[i]);
            }
            else if(s[i]!='#' && t[i]=='#')
            {
                ct1++;
                s1.push_back(s[i]);
                ct2--;
                if(t1.size()>0)
                    t1.pop_back();
                ct2=max(0,ct2);
            }
            else
            {
                ct1++;
                s1.push_back(s[i]);
                ct2++;
                t1.push_back(t[i]);
            }
        }
        
        int ind=min(n1,n2);
        
        if(n1>n2)
        {
            while(ind<n1)
            {
                if(s[ind]=='#')
                {
                    ct1--;
                    if(s1.size()>0)
                        s1.pop_back();
                    ct1=max(ct1,0);
                }
                else
                {
                    ct1++;
                    s1.push_back(s[ind]);
                }
                ind++;
            }
            
        }
        else if(n1<n2)
        {
            while(ind<n2)
            {
                if(t[ind]=='#')
                {
                    ct2--;
                    if(t1.size()>0)
                        t1.pop_back();
                    ct2=max(ct2,0);
                }
                else
                {
                    ct2++;
                    t1.push_back(t[ind]);
                }
                ind++;
            }
        }
        
        if(s1==t1)
            return true;
        
        return false;
            
    }
};