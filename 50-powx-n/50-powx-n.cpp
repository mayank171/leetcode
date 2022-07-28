class Solution {
public:
    double binExp(double a,long long b)
    {
        double ans=1.0;
        while(b)
        {
            if(b&1)
            {
               ans=(ans*a);
               b--;
            }
            else
            {
               a=(a*a);
               b>>=1;   
            }
        }
        
        return ans;
    }
    double myPow(double x, int n) {
        double ans=1.0;
        
        
        long long N;
        if(n<0)
            N=-1*1ll*n;
        else
            N=n;
        
        while(N)
        {
            if(N&1)
            {
                ans=(ans*x);
                N--;
            }
            else
            {
                x=x*x;
                N>>=1;
            }
        }
        
        if(n<0)
            return ans=(double)1/(double)ans;
        return ans;
        
    }
};