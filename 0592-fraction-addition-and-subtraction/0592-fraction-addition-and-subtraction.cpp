class Solution {
public:
    string fractionAddition(string exp) {
        
        if(exp[0]!='-')
        {
            reverse(exp.begin(),exp.end());
            exp.push_back('+');
            reverse(exp.begin(),exp.end());
        }
        
        vector<pair<int,int>> vp;
        
        int n=exp.size();
        
        for(int i=0;i<n;)
        {
            if(exp[i]=='+')
            {
                int k1=0;
                int j=i+1;
                while(j<n && exp[j]>='0' && exp[j]<='9')
                {
                    k1=k1*10+(exp[j]-'0');
                    j++;
                }
                
                j++;
                int k2=0;
                while(j<n && exp[j]>='0' && exp[j]<='9')
                {
                    k2=k2*10+(exp[j]-'0');
                    j++;
                }
                
                vp.push_back({k1,k2});
                i=j;
            }
            else
            {
                
                int k1=0;
                int j=i+1;
                while(j<n && exp[j]>='0' && exp[j]<='9')
                {
                    k1=k1*10+(exp[j]-'0');
                    j++;
                }
                
                j++;
                int k2=0;
                while(j<n && exp[j]>='0' && exp[j]<='9')
                {
                    k2=k2*10+(exp[j]-'0');
                    j++;
                }
                
                vp.push_back({-1*k1,k2});
                i=j;
            }
        }
        
        for(int i=0;i<vp.size();i++)
        {
            cout<<vp[i].first<<" "<<vp[i].second<<endl;
        }
        
        int deno=vp[0].second;
        for(int i=1;i<vp.size();i++)
        {
            deno=(deno*vp[i].second)/__gcd(deno,vp[i].second);
        }
        
        cout<<deno<<endl;
        
        int num=0;
        for(int i=0;i<vp.size();i++)
        {
            num+=(vp[i].first*(deno/vp[i].second));
        }
        
        cout<<num<<endl;
        
        int _g=__gcd(num,deno);
        num=num/_g;
        deno=deno/_g;
        
        if(num<0 && deno<0)
        {
            num*=-1;
            deno*=-1;
        }
        else if(deno<0)
        {
            num*=-1;
            deno*=-1;
        }
        
        string ans="";
        ans+=to_string(num);
        ans+='/';
        ans+=to_string(deno);
        
        return ans;
    }
};