class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
       // int total=1;
        int n=nums.size();
        
        vector<int> ans(n,1);
        ans[1]=nums[0];
        int prev=1;
        for(int i=2;i<n;i++)
        {
            ans[i]=ans[i-1]*nums[i-1];
        }
        
        for(auto &it:ans)
            cout<<it<<" ";
        
        int total=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            ans[i]*=total;
            total*=nums[i];
        }
        
        for(auto &it:ans)
            cout<<it<<" ";
        return ans;
        
        /*
        
        -1  -1  0   0  0
         0   0  0  -9  3
        
        4 -3 2  -1  5 1 -2
        
        4      -12   -24    24   120    120  -240
        -240   -60    20    10   -10    -2     -2
        
        */
        
    }
};