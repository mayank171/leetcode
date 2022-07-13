class Solution {
public:
    bool check(vector<int> &v,int n,vector<long long> &ans,int i,int ssf,int x)
    {
        if(i==n)
        {
            if(ssf==4)
            {
             
                for(int i=0;i<4;i++)
                {
                    if(ans[i]!=x)
                        return false;
                }
                return true;
                
            }
            return false;
        }
        
        
        for(int i=0;i<4;i++)
        {
            if(ans[i]>x)
                return false;
        }
        
        
        
        for(int j=0;j<4;j++)
        {
            if(ans[j]==0)
            {
                ans[j]+=v[i];
                if(check(v,n,ans,i+1,ssf+1,x))
                    return true;
                ans[j]-=v[i];
                break;
            }
            else
            {
                ans[j]+=v[i];
                if(check(v,n,ans,i+1,ssf,x))
                    return true;
                ans[j]-=v[i];    
            }
        }
        
        return false;
    }
    bool makesquare(vector<int>& v) {
     
        int n=v.size();
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=v[i];
        }
         
        if(sum%4!=0)
        {
            return false;
        }
        
        
        
        if(n<4)
            return false;
        
        sort(v.rbegin(),v.rend());
        
        if(v[n-1]>sum/4)
        {
            return false;
        }
        
        int x=sum/4;
        
        vector<long long> ans(4,0);
        
        if(check(v,n,ans,0,0,x))
            return true;
        return false;
        
    }
};