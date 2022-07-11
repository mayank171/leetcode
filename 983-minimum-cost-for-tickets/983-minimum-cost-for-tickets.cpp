class Solution {
public:
   
    int check(vector<int> &days,int n,vector<int> &costs,int ind,set<int> &st,vector<int> &dp)
    {
        if(ind>days[n-1])
            return 0;
        
        
        if(st.find(ind)==st.end())
        {
            //cout<<"~~~~~"<<endl;
            return check(days,n,costs,ind+1,st,dp);
        }
        
        if(dp[ind]!=-1)
            return dp[ind];
        
        int mini=1e8;
        for(int i=0;i<3;i++)
        {
            if(i==0)
               mini=min(mini,costs[i]+check(days,n,costs,ind+1,st,dp));
            else if(i==1)
               mini=min(mini,costs[i]+check(days,n,costs,ind+7,st,dp));
            else if(i==2)
               mini=min(mini,costs[i]+check(days,n,costs,ind+30,st,dp));
           // cout<<mini<<endl;
        }
      //  cout<<"---"<<endl;
        return dp[ind]=mini;
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int n=days.size();
        
        set<int> st;
        
        for(int i=0;i<n;i++)
            st.insert(days[i]);
        
        vector<int> dp(days[n-1]+1,-1);
        
        return check(days,n,costs,days[0],st,dp);
        
//         for(int i=0;i<dp.size();i++)
//         {
//             cout<<dp[i]<<" ";
//         }
//         cout<<endl;
        
//         return dp[dp.size()-1];
        
    }
};