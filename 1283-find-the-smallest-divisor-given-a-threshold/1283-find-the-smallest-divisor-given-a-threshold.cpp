class Solution {
private:
    
    int blackBox(vector<int> &nums,int mid,int n)
    {
        int x=0;
        
        for(int i=0;i<n;i++)
        {
           if(nums[i]<mid)
             x++;
           else if(nums[i]%mid!=0)
           {
               x=x+nums[i]/mid+1;
           }
           else
           {
               x=x+nums[i]/mid;
           }
        }
        cout<<endl;
        
        return x;
    }
    
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int n=nums.size();
        
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        
        int ans=INT_MAX;
        int min=INT_MAX;
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            int sum=blackBox(nums,mid,n);
            //cout<<mid<<" "<<sum<<endl;
            
            if(sum<=threshold)
            {
              //  ans=min(ans,mid);
                if(ans>mid)
                {
                   ans=mid;
                   high=mid-1;
                }    
            }
            else
            {
               
                   low=mid+1;    
            
                
            }
            
        }
        
        return ans;
    }
};