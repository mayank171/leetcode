class Solution {
public:
    
    int mod=1e9+7;
    
    int solve(int low,int &zero,int &one,int &temp,vector<int> &dp)
    {
        //cout<<temp<<endl;
        if(temp>low)
            return 0;
        
        if(temp==low)
            return 0;
        
        if(dp[temp]!=-1)
            return dp[temp];
     //   cout<<"fes"<<endl;
        int x=temp;
        temp+=zero;
        
        int takez=0;
        if(temp<=low)
           takez=(1+solve(low,zero,one,temp,dp))%mod;
        temp=x;
        temp+=one;
        
        int takeo=0;
        if(temp<=low)
           takeo=(1+solve(low,zero,one,temp,dp))%mod;
        temp=x;
        
        return dp[temp]=(takez+takeo)%mod;
    }
    
    int countGoodStrings(int low, int high, int zero, int one) {
        
        int temp=0;
       // cout<<szero<<" "<<sone<<endl;
        vector<int> dp1(low+1,-1);
       // cout<<"cdcdc"<<endl;
        int ans1=solve(low-1,zero,one,temp,dp1);  
       // cout<<"cdsaa<<"<<endl;
        vector<int> dp2(high+1,-1);
        
        int ans2=solve(high,zero,one,temp,dp2);  
        cout<<ans1<<" "<<ans2<<endl;
        return (ans2-ans1+mod)%mod;
    }
};