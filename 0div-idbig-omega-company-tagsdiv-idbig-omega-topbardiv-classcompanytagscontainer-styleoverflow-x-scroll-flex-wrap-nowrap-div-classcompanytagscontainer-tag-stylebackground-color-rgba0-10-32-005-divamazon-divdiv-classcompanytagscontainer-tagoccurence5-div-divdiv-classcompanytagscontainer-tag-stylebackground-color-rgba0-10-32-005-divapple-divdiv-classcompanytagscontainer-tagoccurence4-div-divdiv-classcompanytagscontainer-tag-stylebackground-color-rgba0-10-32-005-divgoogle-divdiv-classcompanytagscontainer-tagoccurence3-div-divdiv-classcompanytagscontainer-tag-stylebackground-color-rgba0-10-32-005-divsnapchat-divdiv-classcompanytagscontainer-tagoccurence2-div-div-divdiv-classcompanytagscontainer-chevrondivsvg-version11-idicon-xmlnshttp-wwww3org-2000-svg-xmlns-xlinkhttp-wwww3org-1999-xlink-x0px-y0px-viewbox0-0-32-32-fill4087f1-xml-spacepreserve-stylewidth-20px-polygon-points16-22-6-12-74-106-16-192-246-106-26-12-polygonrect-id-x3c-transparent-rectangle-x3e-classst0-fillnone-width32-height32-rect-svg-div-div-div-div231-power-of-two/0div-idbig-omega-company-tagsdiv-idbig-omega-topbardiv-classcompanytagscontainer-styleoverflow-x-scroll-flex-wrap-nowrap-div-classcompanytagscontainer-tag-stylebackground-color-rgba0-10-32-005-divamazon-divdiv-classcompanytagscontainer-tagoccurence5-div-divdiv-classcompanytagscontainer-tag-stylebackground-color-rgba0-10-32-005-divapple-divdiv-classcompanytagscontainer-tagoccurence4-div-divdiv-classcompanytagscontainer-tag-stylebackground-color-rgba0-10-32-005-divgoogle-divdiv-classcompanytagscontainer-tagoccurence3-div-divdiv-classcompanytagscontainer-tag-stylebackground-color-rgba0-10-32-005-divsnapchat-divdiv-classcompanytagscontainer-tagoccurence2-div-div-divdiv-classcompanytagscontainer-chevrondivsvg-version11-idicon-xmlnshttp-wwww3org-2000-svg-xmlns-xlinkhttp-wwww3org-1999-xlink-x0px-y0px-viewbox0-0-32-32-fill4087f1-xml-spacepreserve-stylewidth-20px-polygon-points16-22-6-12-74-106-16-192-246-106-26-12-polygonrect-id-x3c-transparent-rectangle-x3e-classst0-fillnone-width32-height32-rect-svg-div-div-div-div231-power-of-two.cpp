class Solution {
public:
    bool isPowerOfTwo(int n) {
        
       // n
        if(n==0)
            return false;
        
        long n1=n;
        long n2=n;
        n2--;
        long x=n1&n2;
        
        if(x==0)
            return 1;
        return 0;
    }
};