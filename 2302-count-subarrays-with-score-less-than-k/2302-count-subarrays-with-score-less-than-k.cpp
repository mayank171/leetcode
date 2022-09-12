class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        
        int n=nums.size();
        int start=0;
        int end=0;
        
        
//         vector<long long> v;
//         for(int i=0;i<n;i++)
//         {
//             v.push_back(nums[i]);
//         }
        
//         for(int i=1;i<n;i++)
//         {
//             v[i]+=v[i-1];
//         }
        
        long long score=0;
        long long ans=0;
        
        while(end<n)
        {
            score+=nums[end];
            
            while(start<n && score*(end-start+1)>=k)
            {
                score-=nums[start];
                start++;
            }
            
            if(score*(end-start+1)<k)
            {
                ans+=end-start+1;
            }
            
            end++;
        }
        
        
        return ans;
    }
};