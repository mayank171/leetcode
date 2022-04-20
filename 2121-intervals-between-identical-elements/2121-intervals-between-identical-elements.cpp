class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        
        
        long long size=arr.size();
        long long maxi=*max_element(arr.begin(),arr.end());
        
        vector<pair<long long,long long>> adj[maxi+1];
        
        for(int i=0;i<size;i++)
        {
            adj[arr[i]].push_back({i,i});
        }
        
        
        for(int i=0;i<maxi+1;i++)
        {
            for(int j=1;j<adj[i].size();j++)
            {
                adj[i][j].second+=adj[i][j-1].second;
            }                

        }
        
        
        // for(int i=0;i<maxi+1;i++)
        // {
        //     for(int j=0;j<adj[i].size();j++)
        //     {
        //         cout<<adj[i][j].first<<","<<adj[i][j].second<<" ";
        //     }
        //     cout<<endl;
        // }
        
        vector<long long> ans(size,0);
        
        for(int i=0;i<maxi+1;i++)
        {
            long long ct=0;
            for(int j=0;j<adj[i].size();j++)
            {
                long long left_sum=0;
                long long left_freq=0;
                long long right_sum=0;
                long long right_freq=0;
                ct=0;
                
                if(j>0)
                {
                    left_sum=adj[i][j-1].second;
                    left_freq=j;
                }
                
                if(j<adj[i].size()-1)
                {
                    right_sum=abs(adj[i][adj[i].size()-1].second-adj[i][j].second);
                    right_freq=adj[i].size()-j-1;
                }
             //   cout<<left_sum<<" "<<left_freq<<" "<<right_sum<<" "<<right_freq<<endl;
                
                ct+=abs(left_freq*1LL*adj[i][j].first-(left_sum));
                ct+=abs((right_sum)-right_freq*1LL*adj[i][j].first);
             //   cout<<ct<<endl;
                ans[adj[i][j].first]=ct;
            }
            
        }
        
        return ans;
        
        
    }
};