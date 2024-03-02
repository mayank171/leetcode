class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int> ans(n);
        
        int k=n-1;
        
        int i=0;
        int j=n-1;
        
        while(i<=j)
        {
            int x=nums[i]*nums[i];
            int y=nums[j]*nums[j];
            
            if(x<y)
            {
                ans[k]=y;
                k--;
                j--;
            }
            else
            {
                ans[k]=x;
                k--;
                i++;
            }
        }
        
        return ans;
    }
};