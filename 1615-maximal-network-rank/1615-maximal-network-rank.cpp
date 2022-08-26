class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        vector<int> adj[n];
        
        int m=roads.size();
        
        for(int i=0;i<m;i++)
        {
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }
       // cout<<"dvdv"<<endl;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            multiset<int> st;
            int ct=0;
            ct+=adj[i].size();
            
            
            for(int j=i+1;j<n;j++)
            {
                int ct1=0;  
                for(int k=0;k<adj[j].size();k++)
                {
                    if(adj[j][k]!=i)
                       ct1++;
                }
                //cout<<ct<<endl;
//                 for(auto &it:st)
//                 {
//                     st1.insert(it);
//                 }
                
                // for(auto &it:st1)
                // {
                //     cout<<it<<" ";
                // }
                // cout<<endl;
            
                if(ans<ct+ct1)
                    ans=ct+ct1;
            }
            
            
        }
        
        return ans;
        
        
    }
};