class Solution {
public:
    
    int isRoot(string s)
    {
        int n=s.length();
        
        int alpha=0;
        int dot1=0;
        int dot2=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='.')
            {
                if(dot1==0)
                    dot1++;
                else
                    dot2++;
            }
            else 
            {
                alpha++;
            }
        }
        
        if(alpha>0)
            return 0;
        else if(dot1==1 && dot2==0)
            return -1;
        else if(dot1==1 && dot2==1)
            return 1;
        else
            return 2;
    }
    
    string simplifyPath(string path) {
        
        int n=path.length();
        
        vector<string> vp;
       // vp.push_back(path[0]);
        
        for(int i=1;i<n;i++)
        {
            int ind=i;
            string str="";
            while(ind<n && path[ind]!='/')
            {
                str+=path[ind];
                ind++;
            }
            
            if(str.size()>0)
               vp.push_back(str);
            
            cout<<str<<endl;
            i=ind;
        }
        
        
        
        stack<string> stk;
        
        
        for(int i=0;i<vp.size();i++)
        {
            string x=vp[i];
            int t=isRoot(x);
            
            cout<<t<<endl;
            
            if(t==0)
            {
                reverse(x.begin(),x.end());
                stk.push(x);
            }
            else if(t==-1)
            {
                
            }
            else if(t==1)
            {
                if(!stk.empty())
                {
                    stk.pop();
                }
            }
            else
            {
                reverse(x.begin(),x.end());
                stk.push(x);
            }
        }
        
        string ans="";
        
        while(!stk.empty())
        {
            string x=stk.top();
            stk.pop();
            ans+='/';
            ans+=x;
            
        }
        
        ans.push_back('/');
        reverse(ans.begin(),ans.end());
        ans.pop_back();
        
        cout<<ans<<endl;
        
        if(ans.size()==0)
            return "/";
        
        return ans;
    }
};














