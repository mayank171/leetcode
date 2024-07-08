class Solution {
public:
    
    int solve(int n,int k)
    {
        if(n==1)
            return 0;
        
        int x=solve(n-1,k);
        return (x+k)%n;
    }
    
    int findTheWinner(int n, int k) {
        
        int ans=solve(n,k);
        return ans+1;
    }
};