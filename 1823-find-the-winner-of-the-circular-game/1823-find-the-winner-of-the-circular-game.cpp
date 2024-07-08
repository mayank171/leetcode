class Solution {
public:
    int findTheWinner(int n, int k) {
        
        vector<int> v;
        for(int i=1;i<=n;i++)
        {
            v.push_back(i);
        }
        
        int ind=0;
        while(v.size()!=1)
        {
            ind=ind+k-1;
            if(ind>=v.size())
            {
                ind=ind%v.size();
            }
            
            auto it=v.begin()+ind;
            v.erase(it);
        }
        
        return v[0];
    }
};