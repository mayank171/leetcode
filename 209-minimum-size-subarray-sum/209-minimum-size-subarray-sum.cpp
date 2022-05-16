class Solution {
private:
    
    long long Sum(vector<int> &nums,int n,int k)
    {
        long long sum=0;
        long long sum1=0;
        
        for(int i=0;i<k;i++)
        {
            sum1+=nums[i];
        }
        
        sum=sum1;
        
        int l=0;
        int r=k;
        
        while(r!=n)
        {
            sum1-=nums[l];
            l++;
            sum1+=nums[r];
            r++;
            
            sum=max(sum1,sum);
        }
        
        return sum;
    }
    
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n=nums.size();
        
        long long sum1=accumulate(nums.begin(),nums.end(),0);
        
        if(sum1<target)
            return 0;
        
        int mini=*min_element(nums.begin(),nums.end());
        
        if(mini>target)
            return 0;
        
        int low=1;
        int high=n;
        
        int flag=0;
        
        int mid;
        
        int ans=0;
        
        while(low<=high)
        {
             mid=low+(high-low)/2;
           // cout<<mid<<endl;
            
            long long k=Sum(nums,n,mid);
           // cout<<k<<endl;
            
            if(k>=target)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        
        cout<<low<<" "<<mid<<" "<<high<<endl;
        
        return ans;
        
        return 0;
        
    }
};