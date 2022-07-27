class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        vector<int> front(n,1);
        vector<int> hash(n,0);
        
        for(int i=1;i<n;i++)
        {
            hash[i]=i;
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0 && front[j]+1>front[i])
                {
                    front[i]=front[j]+1;
                    hash[i]=j;
                }
            }
        }
        
        int ind=0;
        int maxi=-1e8;
        
        for(int i=0;i<n;i++)
        {
            if(front[i]>maxi)
            {
                maxi=front[i];
                ind=i;
            }
        }
        
        vector<int> ans;
        
        while(hash[ind]!=ind)
        {
            ans.push_back(nums[ind]);
            ind=hash[ind];
        }
        
        ans.push_back(nums[ind]);
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        
    }
};