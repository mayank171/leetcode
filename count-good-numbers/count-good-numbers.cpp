class Solution {
public:
    
    int binExp(long long a,long long b,int M)
    {
        int ans=1;
        
        while(b)
        {
            if(b&1)
            {
                ans=(ans*a)%M;
            }
            b>>=1;
            a=(a*a)%M;
        }
        
        return ans;
    }
    
    int countGoodNumbers(long long n) {
        
        int M=1e9+7;
        
        long long ans=1;
        long long ans1=1; 
        
        
         if(n&1)
         {
             ans=binExp(4,n/2,M);
             //ans=(ans*4)%M;
             ans1=binExp(5,n/2+1,M);
             
             cout<<ans<<" "<<ans1<<endl;
             
             ans=(ans*ans1)%M;
         }
         else
         {
             ans=binExp(4,n/2,M);
             //ans=(ans*4)%M;
             ans1=binExp(5,n/2,M);
             
             cout<<ans<<" "<<ans1<<endl;
             
             ans=(ans*ans1)%M;
         }
            
        
        
        return ans;
        
    }
};