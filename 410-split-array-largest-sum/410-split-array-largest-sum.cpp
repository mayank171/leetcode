class Solution {
private:
   int blackBox(vector<int> &nums,int n,int m,int mid)
   {
       int sum=0;
       int maxi=0;
       for(int i=0;i<n;i++)
       {
           if(sum+nums[i]<=mid)
           {
               sum+=nums[i];
           }
           else
           {
               maxi++;
               if(maxi>m)
                   return maxi;
               sum=0;
               i--;
           }
       }
       
       if(0<sum)
       {
           maxi++;
       }
       
       return maxi;
       
   }
public:
    int splitArray(vector<int>& nums, int m) {
        
        int n=nums.size();
        
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        
        
        int ans=low;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
           // cout<<mid<<endl;
            
            int val=blackBox(nums,n,m,mid);
            
            if(val>m)
            {
                low=mid+1;
            }
            else
            {
                ans=mid;
                high=mid-1;
            }
        }
        
        return ans;
        
    }
};