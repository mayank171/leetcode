class Solution {
public:
    
    int solve(vector<int> &cuts,int n,int left,int right,vector<vector<int>> &dp)
    {
       // cout<<n<<" "<<left<<" "<<right<<endl;
        if(left>right)
        {
            return 0;
        }
        
        if(dp[left][right]!=-1)
            return dp[left][right];
        
        int ans=1e9;
        for(int i=left;i<=right;i++)
        {
            ans=min(ans,cuts[right+1]-cuts[left-1]+solve(cuts,cuts[i]-left,left,i-1,dp)+solve(cuts,n-cuts[i]-left,i+1,right,dp));
        }
        
        return dp[left][right]=ans;
            
    }
    
    int minCost(int n, vector<int>& cuts) {
        
        int size=cuts.size();
        cuts.push_back(n);
        reverse(cuts.begin(),cuts.end());
        cuts.push_back(0);
        reverse(cuts.begin(),cuts.end());
        size+=2;
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(size,vector<int>(size,-1));
        return solve(cuts,n,1,size-2,dp);
        
    }
};