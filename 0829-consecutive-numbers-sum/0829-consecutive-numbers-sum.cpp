class Solution {
public:
    int consecutiveNumbersSum(int n) {
        
        int ct=1;
        
        
        for(int i=2;i<sqrt(2*n);i++)
        {
            int x=(i*1ll*(i+1))/2;
            x=n-x;
            
            if(x%i==0)
                ct++;
        }
        
        return ct;
        
    }
};