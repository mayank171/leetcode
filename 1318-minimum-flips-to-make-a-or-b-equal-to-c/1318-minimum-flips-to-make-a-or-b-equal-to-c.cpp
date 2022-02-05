class Solution {
public:
    int minFlips(int a, int b, int c) {
        
        int ct=0;
        for(int i=0;i<32;i++)
        {
            int bit_a=a&(1<<i)?1:0;
            int bit_b=b&(1<<i)?1:0;
            int bit_c=c&(1<<i)?1:0;
            
            if(bit_a==0 && bit_b==0 && bit_c==1)
            {
                ct++;
            }
            else if(bit_a==1 && bit_b==1 && bit_c==0)
            {
                ct+=2;
            }
            else if(bit_a==0 && bit_b==1 && bit_c==0 || bit_a==1 && bit_b==0 && bit_c==0)
            {
                ct++;
            }
            
        }
        
        return ct;
        
    }
};