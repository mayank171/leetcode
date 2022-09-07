class Solution {
public:
    
    bool solve(vector<int> &piles,int n,int i,int j,int A,int B)
    {
        if(i>j)
        {
            if(A>B)
                return true;
            return false;
        }
        
        
        if(solve(piles,n,i+1,j,A+piles[i],B))
            return true;
        if(solve(piles,n,i,j-1,A,B+piles[j]))
            return true;
        
        return false;
    }
    
    
    bool stoneGame(vector<int>& piles) {
        
        int n=piles.size();
        
        return solve(piles,n,0,n-1,0,0);
        
    }
};