class Solution {
public:
    int numberOfArrays(vector<int>& dif, int lower, int upper) {
        
        int n=dif.size();
        
        long  a=lower;
        long  b=lower;
        long  c=lower;
        
        for(int i=0;i<n;i++)
        {
            a=max(dif[i]+c,a);
            b=min(dif[i]+c,b);
            c=dif[i]+c;
        }
        
        long ans=(upper-lower)-(a-b)+1;
        
        if(ans<0)
            return 0;
        
        return ans;
        
        
    }
};