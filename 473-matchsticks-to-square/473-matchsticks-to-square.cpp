class Solution {
public:
    bool check(vector<int> &v,int n,vector<int> ans[],int i,int ssf,int x)
    {
        if(i==n)
        {
            if(ssf==4)
            {
             
                for(int i=0;i<4;i++)
                {
                    long long size=ans[i].size();
                    long long sum=0;
                    for(int j=0;j<size;j++)
                    {
                        sum+=ans[i][j];
                    }
                    if(sum!=x)
                        return false;
                }
                return true;
                
            }
            return false;
        }
        
        
        for(int i=0;i<4;i++)
        {
            long long size=ans[i].size();
            long long sum=0;
            for(int j=0;j<size;j++)
            {
                sum+=ans[i][j];
            }
            if(sum>x)
                return false;
        }
        
        
        
        for(int j=0;j<4;j++)
        {
            if(ans[j].size()==0)
            {
                ans[j].push_back(v[i]);
                if(check(v,n,ans,i+1,ssf+1,x))
                    return true;
                ans[j].pop_back();
                break;
            }
            else
            {
                ans[j].push_back(v[i]);
                if(check(v,n,ans,i+1,ssf,x))
                    return true;
                ans[j].pop_back();    
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
        
        vector<int> ans[4];
        
        if(check(v,n,ans,0,0,x))
            return true;
        return false;
        
    }
};