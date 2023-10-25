class Solution {
public:
    
    int solve(int n,int k)
    {
        if(n==1)
        {
            return 0;
        }
        
        int p=pow(2,n-1);
        p/=2;
        
        if(k<=p)
        {
            return solve(n-1,k);
        }
        else
        {
            if(k&1)
                return solve(n-1,k/2+1);
            return 1-solve(n-1,k/2);
        }
    }
    
    int kthGrammar(int n, int k) {
        
        return solve(n,k);
    }
};