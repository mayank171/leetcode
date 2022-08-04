class Solution {
public:
    
    bool blackBox(vector<int> &nums,long int maxi,long int mid,int n)
    {
        long int opr=0;
        
        for(int i=0;i<n;i++)
        {
            opr+=(nums[i]-1)/mid;
            if(opr>maxi)
                return false;
        }
        
        return true;
    }
    
    int minimumSize(vector<int>& nums, int maxOperations) {
        
        int n=nums.size();
        
        long int low=1;
        long int high=*max_element(nums.begin(),nums.end());
        
        long int ans=0;
        
        while(low<=high)
        {
            long int mid=low+(high-low)/2;
            
            int k=blackBox(nums,maxOperations,mid,n);
            
            if(k)
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