class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> ans;
        ans.push_back(0);
        
        for(int i=1;i<=n;i++)
        {
            int ct=0;
            
            int num=i;
            while(num>0)
            {
                int rsbm=num&-num;
                ct++;
                num-=rsbm;
            }
            ans.push_back(ct);
        }
        
        return ans;
        
    }
};