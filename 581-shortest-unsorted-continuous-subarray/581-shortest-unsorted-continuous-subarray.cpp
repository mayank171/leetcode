class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int> smallLast(n);
        smallLast[n-1]=nums[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
            smallLast[i]=min(nums[i],smallLast[i+1]);
        }
        
        vector<int> largeFront(n);
        largeFront[0]=nums[0];
        
        for(int i=1;i<n;i++)
        {
            largeFront[i]=max(nums[i],largeFront[i-1]);
        }
        
        int ind1=0;
        int ind2=0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=largeFront[i])
            {
                ind1=i;
            }
        }
        
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]!=smallLast[i])
            {
                ind2=i;
            }
        }
        
        if(ind1==0 && ind2==0)
            return 0;
        
        return ind1-ind2+1;
        
    }
};