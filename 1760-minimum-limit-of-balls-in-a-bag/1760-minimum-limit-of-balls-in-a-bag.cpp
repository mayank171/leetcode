class Solution {
private:
    int blackBox(vector<int> &nums,int n,int mid)
    {
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            int x=(nums[i]-1)/mid;
            maxi+=x;
        }
        
        return maxi;
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        
        int n=nums.size();
        
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        
        int ans=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            int k=blackBox(nums,n,mid);
            
            if(k<=maxOperations)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        
        return ans;
        
    }
};