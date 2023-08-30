class Solution {
public:
    
//     int solve(vector<int> &nums,int n,long long mid)
//     {
//         int ind=-1;
//         int mini=1e9;
        
//         for(int i=0;i<n;i++)
//         {
//             if(nums[i]<=mini)
//             {
//                 mini=nums[i];
//                 ind=i;
//             }
//         }
        
//         int ct=0;
//         int rem=0;
//         for(int i=ind-1;i>=0;i--)
//         {
//             ct+=(ceil((float)nums[i]/(float)mini)-1);
//             if(nums[i]%mini==0)
//             {
//                 continue;
//             }
//             else
//             {
//                 mini=nums[i]%mini;
//             }
//             //ct+=(ceil((float)nums[i]/(float)mini)-1);
            
//         }
        
//         cout<<ct<<endl;
//         if(ct<=mid)
//             return true;
//         return false;
//     }
    
    long long minimumReplacement(vector<int>& nums) {
        
//         int n=nums.size();
        
//         long long low=0;
//         long long high=1e15;
//         long long ans=high;
        
//         while(low<=high)
//         {
//             long long mid=low+(high-low)/2;
//             cout<<low<<" "<<mid<<" "<<high<<endl;
            
//             if(solve(nums,n,mid))
//             {
//                 ans=min(ans,mid);
//                 high=mid-1;
//             }
//             else
//             {
//                 low=mid+1;
//             }
//         }
        
//         return ans;
        int n=nums.size();
        
        long long ans=0, prev=nums[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
            int noOfTime=nums[i]/prev;   
            if((nums[i])%prev!=0)
            {
                noOfTime++;
                prev=nums[i]/noOfTime;
            }   
            ans+=noOfTime-1;
        }
        
        return ans;
    }
};