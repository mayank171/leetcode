class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        
        int n=chalk.size();
        
         vector<long long> vp;
        
        for(int i=0;i<n;i++)
        {
            vp.push_back(chalk[i]);
        }
        
        long long sum=0;
        
        for(int i=0;i<n;i++)
        {
            sum+=vp[i];
        }
        
        long long x=k%sum;
        
        for(int i=1;i<n;i++)
        {
            vp[i]+=vp[i-1];
        }
        
        int lb=upper_bound(vp.begin(),vp.end(),x)-vp.begin();
        
        
        if(lb==n)
        {
            return 0;
        }
        
        return lb;
        
    }
};