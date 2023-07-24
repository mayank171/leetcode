class Solution {
public:
    
    double binExp(double a,double b)
    {
        double ans=1;
        long p=labs(b);
        
        while(p)
        {
            if(p&1)
            {
                ans*=a;
            }
            p>>=1;
            a*=a;
        }
        
        return ans;
    }
    
    double myPow(double x, int n) {
        
        
        if(n<0)
        {
            double ans=binExp(x,abs(n));
            ans=1/ans;
            return ans;
        }
        
        int mod=1e9+7;
        double ans=binExp(x,n);
        return ans;    
    }
};