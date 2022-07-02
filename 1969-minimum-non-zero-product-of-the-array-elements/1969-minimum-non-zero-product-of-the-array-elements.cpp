class Solution {
    long long int mod=1e9+7;
public:
    unsigned long long binExp(unsigned long long a,unsigned long long b)
    {
        unsigned long long ans=1;
        while(b)
        {
            if(b&1)
            {
                ans=(ans*a);
            }
            a=(a*a);
            b>>=1;
            
        }
        return ans;
    }
    
    long long binExp1(long long a,long long b)
    {
        long long ans=1;
        while(b)
        {
            if(b&1)
            {
                ans=(ans*a)%mod;
            }
            a=(a*a)%mod;
            b>>=1;
            
        }
        return ans;
    }
    
    
    int minNonZeroProduct(int p) {
        
        unsigned long long x=2;
        unsigned long long y=p;
        unsigned long long val=binExp(x,y);
        
        
        long long  max_val=(val-1)%mod;
        long long  max_val2=(val-2)%mod;
        
        cout<<val<<" "<<max_val<<" "<<max_val2<<endl;
        
        val=(val-1)/2;
      
        
        long long a=binExp1(max_val2,val);
        
        return (a*1LL*max_val)%mod;
        
    }
};