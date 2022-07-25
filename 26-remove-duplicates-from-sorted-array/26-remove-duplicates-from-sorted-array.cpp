class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n=nums.size();
        int low=-1;
        int ct=1;
        int flag=0;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]==nums[i+1] && flag==0)
            {
                flag=1;
                low=i+1;
            }
            else if(nums[i]!=nums[i+1] && low!=-1)
            {
                ct++;
                nums[low]=nums[i+1];
                low++;
            }
            else if(nums[i]!=nums[i+1])
            {
                ct++;
            }
        }
        cout<<ct<<endl;
        
        return ct;
        
    }
};