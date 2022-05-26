class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int> front(n);
        front[0]=nums[0];
        
        vector<int> back(n);
        back[n-1]=nums[n-1];
        
        
        
        for(int i=1;i<n;i++)
        {
            front[i]=max(front[i-1],nums[i]);
        }
        
        for(int i=n-2;i>=0;i--)
        {
            back[i]=min(nums[i],back[i+1]);
        }
        
//         for(int i=0;i<n;i++)
//         {
//             cout<<front[i]<<" ";
//         }
//         cout<<endl;
        
//         for(int i=0;i<n;i++)
//         {
//             cout<<back[i]<<" ";
//         }
//         cout<<endl;
        
        
        int ans=0;
        for(int i=1;i<n-1;i++)
        {
            if(front[i-1]<nums[i] && back[i+1]>nums[i])
            {
                ans+=2;
            }
            else if(nums[i-1]<nums[i] && nums[i]<nums[i+1])
            {
                ans+=1;
            }
            
           // cout<<ans<<endl;
        }
        
        return ans;
        
        
    }
};