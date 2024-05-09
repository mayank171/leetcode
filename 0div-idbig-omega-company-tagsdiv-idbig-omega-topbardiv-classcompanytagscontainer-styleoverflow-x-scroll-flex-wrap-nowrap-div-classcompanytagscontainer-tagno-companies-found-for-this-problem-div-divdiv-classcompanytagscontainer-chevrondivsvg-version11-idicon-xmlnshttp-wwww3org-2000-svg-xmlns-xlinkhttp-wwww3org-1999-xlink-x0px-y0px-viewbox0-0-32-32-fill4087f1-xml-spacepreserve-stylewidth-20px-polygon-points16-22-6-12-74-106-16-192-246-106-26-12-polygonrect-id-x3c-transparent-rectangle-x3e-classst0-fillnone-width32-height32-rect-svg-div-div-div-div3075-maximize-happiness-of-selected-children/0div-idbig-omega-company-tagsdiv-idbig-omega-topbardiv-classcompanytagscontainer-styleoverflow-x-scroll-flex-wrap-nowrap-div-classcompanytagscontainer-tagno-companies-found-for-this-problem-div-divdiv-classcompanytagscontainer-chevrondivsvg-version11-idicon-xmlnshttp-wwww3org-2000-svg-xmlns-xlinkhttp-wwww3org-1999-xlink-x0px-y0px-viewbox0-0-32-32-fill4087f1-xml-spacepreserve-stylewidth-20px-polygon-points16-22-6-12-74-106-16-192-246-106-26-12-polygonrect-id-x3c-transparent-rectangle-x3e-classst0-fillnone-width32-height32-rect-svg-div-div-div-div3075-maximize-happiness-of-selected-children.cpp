class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        
        int n=happiness.size();
        sort(happiness.rbegin(),happiness.rend());
        
        int p=0;
        long long ans=0;
        
        for(int i=0;i<n;i++)
        {
            if(k>0 && happiness[i]-p>0)
            {
                ans+=(happiness[i]-p);
                k--;
                p++;
            }
            else
                break;
        }
        
        return ans;
    }
};