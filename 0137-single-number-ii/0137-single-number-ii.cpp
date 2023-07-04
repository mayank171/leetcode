class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int n=nums.size();
        int ans=0;
        for(int i=31;i>=0;i--)
        {
            int one=0;
            for(int j=0;j<n;j++)
            {
                int x=nums[j]&(1<<i);
                if(x)
                {
                    one++;
                }
            }
            if(one%3!=0)
            {
                ans=(ans|(1<<i));
            }
        }
        
        return ans;
    }
};