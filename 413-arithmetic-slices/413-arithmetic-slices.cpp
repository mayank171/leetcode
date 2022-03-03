class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int size=nums.size();
        
        if(size<3)
            return 0;
        
        vector<int> ans(size);
        ans[0]=0;
        ans[1]=0;
        
        int ct=0;
        
        for(int i=2;i<size;i++)
        {
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2])
            {
                ct++;
                ans[i]=ct;
            }
            else
            {
                ct=0;
                ans[i]=ct;
            }
        }
        
        for(auto &it:ans)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        
        int maxi=accumulate(ans.begin(),ans.end(),0);
        
        return maxi;
    }
};