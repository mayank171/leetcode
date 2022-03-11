class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        
        
        int size=encoded.size();
        
        int xor1=0;
        
        for(int i=1;i<=size+1;i++)
        {
            xor1^=i;
        }
        
        int xor2=0;
        
        for(int i=1;i<size;i+=2)
        {
            xor2^=encoded[i];
        }
        
        xor1=xor1^xor2;
        
        cout<<xor1<<endl;
        
        vector<int> ans;
        ans.push_back(xor1);
        
        for(int i=0;i<size;i++)
        {
            ans.push_back(xor1^encoded[i]);
            xor1=xor1^encoded[i];
        }
        
        return ans;
        
    }
};