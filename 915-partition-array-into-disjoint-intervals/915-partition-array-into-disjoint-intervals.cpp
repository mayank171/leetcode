class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int> v1;
        v1.push_back(nums[0]);
        
        for(int i=1;i<n;i++)
        {
            v1.push_back(max(v1[i-1],nums[i]));
        }
        
        vector<int> v2(n);
        v2[n-1]=nums[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
            v2[i]=min(v2[i+1],nums[i]);
        }
        
        
//         for(auto &it:v1)
//         {
//             cout<<it<<" ";
//         }
//         cout<<endl;
        
//         for(auto &it:v2)
//         {
//             cout<<it<<" ";
//         }
//         cout<<endl;
        
        
        
        int ans=n;
        for(int i=n-1;i>0;i--)
        {
            if(v1[i-1]<=v2[i])
            {
                ans=i;
            }
        }
        
        return ans;
        
        
        
    }
};