class Solution {
public:
    vector<int> singleNumber(vector<int>& arr) {
        
        int n=arr.size();
        
        int xorr=0;
        for(int i=0;i<n;i++)
        {
            xorr^=arr[i];
        }
        
        int bit=-1;
        for(int i=0;i<32;i++)
        {
            int x=xorr&(1<<i);
            if(x)
            {
                bit=i;
                break;
            }
        }
        
        int a=0;
        int b=0;
        
        for(int i=0;i<n;i++)
        {
            int x=arr[i]&(1<<bit);
            if(x)
                a^=arr[i];
            else
                b^=arr[i];
        }
        
        return {a,b};
    }
};