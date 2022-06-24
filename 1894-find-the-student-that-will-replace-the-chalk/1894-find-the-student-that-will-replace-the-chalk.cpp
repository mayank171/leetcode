class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        
        int n=chalk.size();
        
        long long sum=0;
        
        vector<long long> chalk1;
        
        for(int i=0;i<n;i++)
        {
            chalk1.push_back(chalk[i]);
        }
        
        for(int i=1;i<n;i++)
        {
            chalk1[i]+=chalk1[i-1];
        }
        sum=chalk1[n-1];
        
        sum=k%sum;
        
        int ind=upper_bound(chalk1.begin(),chalk1.end(),sum)-chalk1.begin();
        
        if(ind==n)
            return 0;
        else
            return ind;
        
    }
};