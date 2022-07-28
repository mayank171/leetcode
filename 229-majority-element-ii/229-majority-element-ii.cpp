class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int num1=-1e8;
        int num2=-1e8;
        int ct1=0;
        int ct2=0;
        
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            if(num1==nums[i])
                ct1++;
            else if(num2==nums[i])
                ct2++;
            else if(ct1==0)
                num1=nums[i],ct1=1;
            else if(ct2==0)
                num2=nums[i],ct2=1;
            else
                ct1--,ct2--;
        }
        
        int c1=0;
        int c2=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==num1)
                c1++;
            if(nums[i]==num2)
                c2++;
        }
        
        if(c1>n/3 && c2>n/3)
            return {num1,num2};
        else if(c1>n/3)
            return {num1};
        else if(c2>n/3)
            return {num2};
        else
            return {};
        
    }
};