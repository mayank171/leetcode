class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> ans;
        for(int i=0;i<=n;i++)
        {
            // int ct=0;
            // for(int j=0;j<32;j++)
            // {
            //     if(i&(1<<j))
            //     {
            //         ct++;
            //     }
            // }
            // ans.push_back(ct);
            
            int x=i;
            int ct=0;
            while(x>0)
            {
                x-=(x&(-x));
                ct++;
            }
            ans.push_back(ct);
        }
        
        return ans;
        
    }
};