class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
//         unordered_map<int,int> m;
        
//         int N=nums.size();
        
//         for(int i=0;i<N;i++)
//         {
//             m[nums[i]]++;
//         }
        
//         for(auto it:m)
//         {
//             if(it.second==1)
//             {
//                 return it.first;
//             }
//         }
//         return 0;
        
        int n=nums.size();
        
        if(n==1)
        {
            return nums[0];
        }
        
        sort(nums.begin(),nums.end());
        
        int ans=0;
        int flag=0;
        
        for(int i=1;i<n-1;i+=3)
        {
            if(nums[i-1]!=nums[i] && nums[i]==nums[i+1])
            {
                flag=1;
                ans=nums[i-1];
                break;
            }
            else if(nums[i-1]==nums[i] && nums[i]!=nums[i+1])
            {
                flag=1;
                ans=nums[i+1];
                break;
            }
            
        }
        
        if(flag==0)
        {
            ans=nums[n-1];
        }
        
        return ans;
    }
};