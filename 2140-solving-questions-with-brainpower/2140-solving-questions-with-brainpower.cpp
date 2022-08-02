class Solution {
public:
    long long check(vector<long long> &dp,vector<vector<int>> &v,int n,int ind)
    {
        if(ind>=n)
            return 0;
        
        if(dp[ind]!=-1)
            return dp[ind];
        
        long long take=0;
        long long notTake=0;
        
        take=v[ind][0]+check(dp,v,n,ind+v[ind][1]+1);
        notTake=0+check(dp,v,n,ind+1);
        //cout<<take<<" "<<notTake<<endl;
        
        
        return dp[ind]=max(take,notTake);
    }
    
    long long mostPoints(vector<vector<int>>& questions) {
        
        int n=questions.size();
        int ind=0;
        vector<long long> dp(n,-1);
        return check(dp,questions,n,ind);
        
    }
};