class Solution {
public:
    
    // static bool comp(int a,int b)
    // {
    //     if(abs(a)==abs(b) || abs(a)<abs(b))
    //         return true;
    //     return false;
    // }
    
    int findMaxK(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        int i=0;
        int j=nums.size()-1;
        
        int ans=-1;
        while(i<j)
        {
            if((nums[i]>0 && nums[j]>0)||(nums[i]<0 && nums[j]<0))
                break;
            
            if(nums[j]+nums[i]>0)
            {
                j--;
            }
            else if(nums[j]+nums[i]<0)
            {
                i++;
            }
            else
            {
                ans=max(ans,abs(nums[i]));
                i++;
                j--;
            }
        }
        
        return ans;
        
//         for(auto &it:nums)
//         {
//             cout<<it<<" ";
//         }
//         cout<<endl;
        
//         int ans=-1;
//         // for(int i=0;i<nums.size()-1;i++)
//         // {
//         //     if((nums[i+1]<0 && nums[i]==abs(nums[i+1])) || (nums[i]<0 && abs(nums[i])==nums[i+1]))
//         //     {
//         //         ans=max(ans,abs(nums[i]));
//         //     }
//         // }
        
//         return ans;
    }
};