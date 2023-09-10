class Solution {
public:
    int countOrders(int n) {
        
        if(n==1)
            return 1;
        
        int ans=1;
        
        int nn=2*n;
        
        int mod=1e9+7;
        
        for(int i=nn-1;i>=1;i-=2)
        {
            int p=i;
            if(p==1)
            {
                break;
            }
            ans=(ans*1ll*p)%mod;
        }
        
        ans=(ans*1ll*n)%mod;
        
        int p=1;
        n--;
        while(n!=1)
        {
            p=(p*1ll*n)%mod;
            n--;
        }
        
        ans=(ans*1ll*p)%mod;
        
        return ans;
    }
};