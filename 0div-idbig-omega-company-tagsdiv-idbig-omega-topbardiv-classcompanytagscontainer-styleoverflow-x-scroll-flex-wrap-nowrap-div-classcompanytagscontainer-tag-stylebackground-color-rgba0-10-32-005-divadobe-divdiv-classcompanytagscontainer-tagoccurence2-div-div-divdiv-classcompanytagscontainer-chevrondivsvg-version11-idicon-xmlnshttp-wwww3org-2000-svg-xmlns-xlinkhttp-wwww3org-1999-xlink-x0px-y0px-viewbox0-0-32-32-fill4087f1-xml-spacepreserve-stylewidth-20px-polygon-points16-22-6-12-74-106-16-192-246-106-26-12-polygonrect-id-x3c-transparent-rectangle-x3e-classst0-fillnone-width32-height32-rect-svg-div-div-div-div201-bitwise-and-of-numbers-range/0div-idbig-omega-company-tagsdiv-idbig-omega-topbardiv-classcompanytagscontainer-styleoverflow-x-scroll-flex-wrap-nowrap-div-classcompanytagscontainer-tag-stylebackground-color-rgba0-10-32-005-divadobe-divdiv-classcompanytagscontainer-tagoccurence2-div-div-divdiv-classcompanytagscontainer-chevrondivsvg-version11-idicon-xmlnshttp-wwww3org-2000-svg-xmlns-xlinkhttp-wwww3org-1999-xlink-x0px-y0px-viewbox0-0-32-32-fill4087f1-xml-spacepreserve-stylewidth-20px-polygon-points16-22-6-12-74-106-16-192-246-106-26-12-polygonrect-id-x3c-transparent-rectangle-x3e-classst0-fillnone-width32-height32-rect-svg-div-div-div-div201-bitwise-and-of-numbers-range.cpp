class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        
        if(left==0 || right ==0)
            return 0;
        
        if(left==1 && right!=1)
            return 0;
        
        if(left!=1 && right==1)
            return 0;
        
        if(left==1 && right==1)
            return 1;
        
        int ans=0;
        
        while(true)
        {

            int msb_a=log2(left);
            int msb_b=log2(right);
            
            if(msb_a!=msb_b)
                return ans;
            
            ans+=(1<<msb_a);
            left-=(1<<msb_a);
            if(left<=0)
                break;
            right-=(1<<msb_b);
            if(right<=0)
                break;
        }
        
        return ans;
        
    }
};