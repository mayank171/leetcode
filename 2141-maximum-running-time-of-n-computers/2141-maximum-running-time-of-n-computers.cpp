class Solution {
public:
    
    int solve(vector<int> &v,int size,int n,long long mid)
    {
        long long ans=0;
        for(int i=0;i<size;i++)
        {
            if(v[i]<=mid)
                ans+=v[i];
            else
                ans+=mid;
        }
        
        if(ans/(long)n>=mid)
            return 1;
        return 0;
    }
    
    
    long long maxRunTime(int n, vector<int>& batteries) {
        
        int size=batteries.size();
        
        long long low=1;
        long long high=1e15;
        
        long long ans=0;
        
        while(low<=high)
        {
            long long mid=low+(high-low)/2;
            
            if(solve(batteries,size,n,mid))
            {
                ans=max<long long>(ans,mid);
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        
        return ans;
    }
};