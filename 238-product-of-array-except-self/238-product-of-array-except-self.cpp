class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int> v1;
        v1.push_back(nums[0]);
        
        for(int i=1;i<n;i++)
        {
            v1.push_back(v1[i-1]*nums[i]);
        }
        
        vector<int> v2(n);
        v2[n-1]=nums[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
            v2[i]=v2[i+1]*nums[i];
        }
        
      //  reverse(v2.begin(),v2.end());
        
        for(auto &it:v1)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        
        for(auto &it:v2)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        
        
        
        for(int i=1;i<n-1;i++)
        {
            nums[i]=v1[i-1]*v2[i+1];
        }
        
        nums[0]=v2[1];
        
        nums[n-1]=v1[n-2];
        
        return nums;
        
    }
};