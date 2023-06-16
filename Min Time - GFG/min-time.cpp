//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    vector<int> left;
    vector<int> right;
    
    long long solve(int pos,vector<int> &types,int ind,vector<vector<long long>> &dp,int move)
    {
        if(ind==types.size())
          return 0;
           
        if(dp[ind][move]!=-1)
          return dp[ind][move];
        
        long long mini=1e15;
        
        long long take=0;
        int x=abs(pos-right[ind]);
        
        take=x+abs(right[ind]-left[ind])+solve(left[ind],types,ind+1,dp,0);
        if(ind+1==types.size())
        {
            take+=abs(left[ind]-0);   
        }
        long long nottake=0;
        int y=abs(pos-left[ind]);
        nottake=y+abs(left[ind]-right[ind])+solve(right[ind],types,ind+1,dp,1);
        if(ind+1==types.size())
        {
            nottake+=abs(right[ind]-0);   
        }
        return dp[ind][move]=min(take,nottake);
    }
  
    long long minTime(int n, vector<int> &locations, vector<int> &types) {
         
         vector<pair<int,int>> vp;
         set<int> st;
         int maxi=0;
         for(int i=0;i<n;i++)
         {
             maxi=max(maxi,locations[i]);
             st.insert(types[i]);
             vp.push_back({types[i],locations[i]});
         }
         
         sort(vp.begin(),vp.end());
         
         for(int i=0;i<n;i++)
         {
             int t=vp[i].first;
             int start=vp[i].second;
             int end=vp[i].second;
             int j=i;
             while(j<n && vp[j].first==t)
             {
                 end=max(end,vp[j].second);
                 start=min(start,vp[j].second);
                 j++;
             }
             
             
             left.push_back(start);
             right.push_back(end);
             i=j-1;
         }
         
        //  for(auto &it:left)
        //     cout<<it<<" ";
        //  cout<<endl;
         
        //  for(auto &it:right)
        //     cout<<it<<" ";
        //  cout<<endl;
         
         
         
         vector<int> types1;
         for(auto &it:st)
         {
             types1.push_back(it);
         }
         
         vector<vector<long long>> dp(types.size(),vector<long long>(2,-1));
         return solve(0,types1,0,dp,0);
    }
    
     
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> locations(n);
        for(int i=0;i<n;i++){
            cin>>locations[i];
        }
        
        
        vector<int> types(n);
        for(int i=0;i<n;i++){
            cin>>types[i];
        }
        
        Solution obj;
        long long res = obj.minTime(n, locations, types);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends