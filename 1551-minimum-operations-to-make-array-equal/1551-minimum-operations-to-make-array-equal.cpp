class Solution {
public:
    int minOperations(int n) {
     
        int ans=0;
        
        if(n&1)
        {
            int x=(2*n)/2;
            for(int i=1;i<=x;i+=2)
            {
                ans+=(x-i);
            }
        }
        else
        {
            int x=n;
            for(int i=1;i<=n;i+=2)
            {
                ans+=(n-i);
            }
        }
        
        return ans;
    }
};