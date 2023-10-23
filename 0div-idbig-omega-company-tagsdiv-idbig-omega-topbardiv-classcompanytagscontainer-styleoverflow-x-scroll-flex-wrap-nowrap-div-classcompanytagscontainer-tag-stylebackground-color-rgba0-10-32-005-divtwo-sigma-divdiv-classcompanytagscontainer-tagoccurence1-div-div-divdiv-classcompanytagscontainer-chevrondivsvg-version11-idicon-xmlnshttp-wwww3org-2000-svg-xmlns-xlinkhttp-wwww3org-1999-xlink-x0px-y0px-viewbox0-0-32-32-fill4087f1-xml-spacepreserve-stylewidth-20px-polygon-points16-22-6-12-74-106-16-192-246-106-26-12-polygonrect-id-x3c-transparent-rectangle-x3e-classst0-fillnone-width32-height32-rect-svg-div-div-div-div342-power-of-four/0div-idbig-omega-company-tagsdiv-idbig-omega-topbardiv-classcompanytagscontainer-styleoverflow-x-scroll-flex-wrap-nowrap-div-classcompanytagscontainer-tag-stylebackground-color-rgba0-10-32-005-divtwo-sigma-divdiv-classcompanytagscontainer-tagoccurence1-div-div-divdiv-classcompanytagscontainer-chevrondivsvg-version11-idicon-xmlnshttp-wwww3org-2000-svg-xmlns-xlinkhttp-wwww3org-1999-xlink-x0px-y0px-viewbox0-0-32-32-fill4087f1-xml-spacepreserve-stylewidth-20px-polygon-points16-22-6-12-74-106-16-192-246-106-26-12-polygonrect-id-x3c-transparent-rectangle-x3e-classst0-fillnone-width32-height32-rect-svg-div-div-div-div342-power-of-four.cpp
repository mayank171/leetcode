class Solution {
public:
    bool isPowerOfFour(int n) {
        
        if(n==1)
            return true;
        
        if(n==0)
            return false;
        
        long nn=n;
        
        long y=nn&(nn-1);
    //    cout<<y<<endl;
        
        if(y==0)
        {
            int p=log2(n);
        //    cout<<p<<endl;
            if(p&1)
                return false;
            return true;
        }
        
        return false;
    }
};