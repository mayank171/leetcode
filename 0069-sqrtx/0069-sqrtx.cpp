class Solution {
public:
    int mySqrt(int x) {
        
        long low=1;
        long high=x;
        
        int ans=0;
        while(low<=high)
        {
            long mid=(low+high)/2;
            
            if(mid*mid==x)
            {
                ans=mid;
                break;
            }
            else if(mid*mid>x)
            {
                high=mid-1;
            }
            else
            {
                ans=mid;
                low=mid+1;
            }
        }
        
        return ans;
    }
};