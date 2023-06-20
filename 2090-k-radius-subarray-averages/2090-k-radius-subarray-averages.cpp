class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        vector<long long> v1;
        v1.push_back(nums[0]);
        
        for(int i=1;i<n;i++)
        {
            v1.push_back(v1.back()+nums[i]);
        }
        
        vector<long long> v2;
        v2.push_back(nums[n-1]);
        
        for(int i=n-2;i>=0;i--)
        {
            v2.push_back(v2.back()+nums[i]);
        }
        
        reverse(v2.begin(),v2.end());
        
        vector<int> ans(n,-1);
        
        for(int i=0;i<n;i++)
        {
            if(i-k>=0 && i+k<n)
            {
                long long l=v2[i-k]-v2[i];
                long long r=v1[i+k]-v1[i];
                
                long long a=l+r+nums[i];
                
                int x=a/(2*k+1);
                
                ans[i]=x;
            }
        }
        
        return ans;
    }
};