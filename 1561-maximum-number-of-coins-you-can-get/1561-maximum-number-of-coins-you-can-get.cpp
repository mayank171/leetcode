class Solution {
public:
    int maxCoins(vector<int>& piles) {
        
        int size=piles.size();
        
        sort(piles.begin(),piles.end());
        
        int ct=size/3;
        int ans=0;
        for(int i=size-2;i>=0;i-=2)
        {
            ans+=piles[i];
            ct--;
            
            if(ct==0)
                break;
        }
        
        return ans;
        
    }
};