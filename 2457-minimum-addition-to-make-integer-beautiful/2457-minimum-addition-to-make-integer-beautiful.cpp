class Solution {
public:
    
    long long solve(long long n)
    {
        long long sum=0;
        while(n)
        {
            sum+=n%10;
            n=n/10;
        }
        
        return sum;
    }
    
    long long makeIntegerBeautiful(long long n, int target) {
        
        long long int p=10;
        long long m=n;
        
        while(solve(n)>target)
        {
            n=ceil(n/(double)p)*p;
            p=p*10;
        }
        
        return n-m;
        
    }
};