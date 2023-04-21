class Solution {
public:
    
    int mod=1e9+7;
    int solve(int g,int Profit,vector<int> &group,vector<int> & profit,int ind,vector<vector<vector<int>>> &dp,int peps)
    {
        if(peps>g)
            return 0;
        
        if(ind<0)
        {
            if(Profit<=0 && peps<=g)
                return 1;
            return 0;
        }
        
        //cout<<ind<<" "<<Profit<<" "<<peps<<endl;
        
        if(Profit<=0)
            Profit=0;
        
        if(Profit>=0 && dp[ind][peps][Profit]!=-1)
            return dp[ind][peps][Profit];
        
        int take=0;
        int nottake=0;
        //cout<<"-"<<endl;
        take=solve(g,Profit-profit[ind],group,profit,ind-1,dp,peps+group[ind]);
        //cout<<"++"<<endl;
        nottake=solve(g,Profit,group,profit,ind-1,dp,peps);
        
        return dp[ind][peps][Profit]=(take+nottake)%mod;
    }
    
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        
        int size=group.size();
        int peps=0;
        vector<vector<vector<int>>> dp(size+1,vector<vector<int>>(n+1,vector<int>(minProfit+1,-1)));
        return solve(n,minProfit,group,profit,size-1,dp,peps);
        
    }
};